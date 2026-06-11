#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
using lint=long long;
const int inf=1000000007;
const int MOD=1000000007;
bool judge(vector<int> const& a,lint k,lint fac){
    bool res=true;
    int n=a.size();
    vector<lint> buf(n);
    rep(i,n){
        buf[i]=a[i]%fac;
    }
    sort(buf.begin(),buf.end());
    lint sm=0;
    rep(i,n)sm+=fac-buf[i];
    //sm%=fac;
    lint sa=0;
    rep(i,n){
        sa+=buf[i];
        sm-=fac-buf[i];
        if(sa>=sm&&(sa-sm)%fac==0){
            if(sa<=k)return true;  
        }
    }
    return false;
}
signed main(){
  int n,k;cin>>n>>k;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  lint sm=0;
  rep(i,n)sm+=a[i];
  vector<lint> p;
  lint buf=sm;
  for(int i=1;i<100000;++i){
      if(sm%i==0){
          p.push_back(i);
          p.push_back(sm/i);
      }
  }
  sort(p.begin(),p.end());
  lint res=1;
  for(auto const& val:p){
      if(judge(a,k,val)){
          res=max(res,val);
      }
  }
  cout<<res<<"\n";
  return 0;
}