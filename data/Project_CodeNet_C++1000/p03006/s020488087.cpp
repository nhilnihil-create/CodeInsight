#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int> >a(n);
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  if(n==1)
  {
    cout<<1<<endl;
    return 0;
  }
  set<pair<int,int> >s;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)s.insert({(a[i].first-a[j].first),(a[i].second-a[j].second)});
  }
  int ans=50;
  for(auto x: s)
  {
    //cout<<x.first<<" "<<x.second<<endl;
    vector<vector<int> >adj(n);
    int count=0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j)continue;
        if((a[i].first-a[j].first)==x.first && (a[i].second-a[j].second)==x.second)
        {
          if(adj[j].size()>0 && adj[j][0]==i)continue;
          adj[i].push_back(j);
          count++;
          break;
        }
      }
    }
    //cout<<count<<endl;
    if(ans>(n-count))ans=n-count;
  }
  cout<<ans<<endl;
  return 0;
}