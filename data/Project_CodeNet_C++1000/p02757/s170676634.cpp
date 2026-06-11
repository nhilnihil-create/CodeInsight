#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;





int main(){
  ll n,p;
  string s;
  vector<ll> u(n);
  cin >>n>>p>>s;
  
  if(10%p==0){// p=2,5の場合
    ll ans =0;
    rep(i,n){
      if((s[i]-'0')%p==0){
        ans +=i+1;
      }
    }
    cout<<ans<<endl;
    return 0;
  }
  
  
  //uの準備
  int ten =1;
  for(int i=n-1; i>=0;--i){
    int  a=(s[i]-'0')*ten%p;
    u[i]= (u[i+1]+a)%p;
    ten=10*ten%p;
  }
  
  vector<int> cnt(p);
  
  ll ans=0;
  
  for (int i=n; i>=0;--i){
    ans+=cnt[u[i]];
    cnt[u[i]]++;
  }
  
  cout<<ans<<endl;
  return 0;

}
