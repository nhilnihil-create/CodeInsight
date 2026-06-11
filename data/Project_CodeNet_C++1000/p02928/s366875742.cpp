#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const ll INF = (1LL << 31) - 1;
const double pi=acos(-1);

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll>a(n);
  rep(i,n)cin >> a[i];
  ll ans=0;
  rep(i,n){
    ll cnt1=0,cnt2=0;
    rep(j,i){
      if(a[j]>a[i]){
        cnt1++;
      }
    }
    rep(j,n){
      if(a[j]>a[i]){
        cnt2++;
      }
    }
    ans+=cnt1*k+(cnt2%MOD)*((k*(k-1)/2)%MOD);
    ans%=MOD;
  }
  
  cout << ans<< endl;
  
    
}
