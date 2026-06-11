#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using I=long long;
#define rep(i,n) for(I i=0;i<n;++i)

I get(I x,I k){return (x>>k)&1;}
int main(){
  I n;
  cin>>n;
  vector<I> a(n);
  rep(i,n)cin>>a[i];
  vector<I> es;
  I ans=0;
  rep(k,62){
    I cnt=0;
    rep(i,n)cnt+=get(a[i],k);
    if(cnt%2)ans+=1LL<<k;
    else es.push_back(k);
  }
  reverse(es.begin(),es.end());
  I cur=0;
  for(I k:es){
    if(n==0)continue;
    rep(i,n){
      if(get(a[i],k)){
        swap(a.back(),a[i]);
      break;}
    }
    I p=a.back();
    if(!get(p,k))
      continue;
    a.pop_back();
    n--;
    rep(i,n){
      if(get(a[i],k))
        a[i]^=p;
    }
    if(!get(cur,k))
      cur^=p;
  }
  for(I k:es)
    if(get(cur,k))
      ans+=2LL<<k;
  cout<<ans<<endl;
}
    
