#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,s,id=1,wei=0,nid;
  cin>>n;s=n;
  vector<int>a(n),b;
  rep(i,n)cin>>a[i];
  map<int,int>ma;
  rep(i,n)ma[a[i]]++;
  for(auto tp:ma)b.push_back(tp.second);
  sort(all(b),greater<int>());
  rep(i,b.size())
  {
    nid=n/b[i]+1+wei;
    repi(j,id,nid)cout<<n/(j-wei)<<"\n";
    id=nid;
    n-=b[i];
    wei++;
  }
  repi(i,nid,s+1)cout<<0<<"\n";
  cout<<endl;
  return 0;
}
