#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll>P;

ll dp[100100];
ll N,K;
ll ans;
long long mod_pow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  rep(i,100100){dp[i]=0;}
  cin>>N>>K;
  for(ll i=K;i>0;i--){
    ll num = K/i;
    ll tmpCount = mod_pow(num, N, (ll)MOD);
    dp[i] = tmpCount;
    ll r=i*2;
    while(r<=K){
      dp[i]=dp[i]+(MOD-dp[r]);
      dp[i]%=MOD;
      r+=i;
    }
  }
  ll ans=0;
  for(ll i=1;i<=K;i++){
  	ans+=i*dp[i];
    ans%=MOD;
  }
  cout<<ans;
}