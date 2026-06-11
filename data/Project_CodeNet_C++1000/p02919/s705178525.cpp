#include<bits/stdc++.h>
using namespace std;
int main() {
  int64_t n,i,i1,i2,j1,j2,ans=0;
  cin>>n;
  vector<int64_t> p(n+1);
  map<int64_t,int64_t> m;
  set<int64_t> s={0,n+1};
  m[0]=0;
  m[n+1]=n+1;
  for(i=1;i<=n;i++){
    cin>>p.at(i);
    m[p.at(i)]=i;
    s.insert(i);
  }
  for(i=1;i<=n;i++){
    auto lb=s.lower_bound(m.at(i));
    i1=*prev(lb,1);
    if(i1==0) i2=0;
    else i2=*prev(lb,2);
    j1=*next(lb,1);
    if(j1==n+1) j2=n+1;
    else j2=*next(lb,2);
    s.erase(m.at(i));
    ans+=i*((i1-i2)*(j1-m.at(i))+(m.at(i)-i1)*(j2-j1));
  }
  cout<<ans<<endl;
}