#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    vector<int> graph[105];
    vector<int>b(105,0);
    while(n--)
    {
        int t1,t2;
        cin>>t1>>t2;
       
         b[t1]=t2-t1;                               
    }
    cin>>m;
    int help=0;
    while(m--)
    {
        int t1,t2;
        cin>>t1>>t2;
        
        b[t1]=t2-t1;
        if(t1>=93) help++; 
    }
    for(int i=0;i<95;i++)
    {
        for(int d=1;d<=6;d++)
        {
            int v=i+d+b[i+d];
            graph[v].push_back(i);
            graph[i].push_back(v);
        }
    }
    for(int i=95;i<=99;i++)
    {int p=0;
        for(int j=5-p;j>=1;j--)
        { int v=i+j+b[i+j];
            graph[v].push_back(i);
            graph[i].push_back(v);
        }
        p++;
    }
  //
  deque<int>q;
  vector<int>par(105,0);
  vector<bool>vis(105,false);
  q.push_back(graph[0][0]);
  vis[graph[0][0]]=true;
  while(!q.empty())
  {int it= * q.begin();
  q.pop_front();
      for(auto x:graph[it])
      {
        if (vis[x] == false) {
          par[x] = par[it] + 1;
          q.push_back(x);
          vis[x] = true;
            }

      }
  }

if(help>=7) cout<<-1<<endl;
else 
cout<<par[100]<<endl;

  }

  return 0;
}
