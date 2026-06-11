#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int n,m,i,j,k,l,w,l1=0,l2,l3;
  cin>>n>>m;
  cin>>w;
  map<int,set<int> > m1;
  vector<int> v(n+1),v1(m+1);
  for(i=1;i<=w;i++) {
    cin>>j>>k;m1[j].insert(k);
    v[j]++;
    v1[k]++;
  }
  l=0;
  for(i=1;i<=n;i++)
  {
    if(l<=v[i])
    {
      l=v[i];
    }
  }
  for(i=1;i<=m;i++)
  {
    if(l1<=v1[i]) {l1=v1[i];}
  }
    set<int> s1,s2;
    for(i=1;i<=n;i++)
    {
      if(l==v[i]) s1.insert(i);
    }
    for(i=1;i<=m;i++)
    {
      if(l1==v1[i]) s2.insert(i);
    }
    bool hi=false;
   for(auto it=s1.begin();it!=s1.end();it++){
     for(auto it1=s2.begin();it1!=s2.end();it1++)
     {
       j=*it;k=*it1;
        if(!m1.count(j)||m1[j].find(k)==m1[j].end())
        {
          hi=true;
          break;
        }
     }
     if(hi) break;
   }
  if(hi) cout<<l+l1;
  else cout<<l+l1-1;
}