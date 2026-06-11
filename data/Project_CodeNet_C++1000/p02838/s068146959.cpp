#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define RREP(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;

using namespace std;


ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = (ans*x) % MOD;
        x = (x*x) % MOD;
        n = n >> 1;
    }
    return ans;
}

ll cnt[100] = {};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll N, ans = 0; cin >> N;
  vector<ll> A(N);
  REP(i,N){
    cin >> A[i];
    REP(j,60) cnt[j] += (A[i] >> j) & 1;
  }
  REP(j,60){
    ans += ((cnt[j] * (N-cnt[j])) % MOD) * mpow(2, j);
    ans %= MOD;
  }
  cout << ans;
  
  return 0;
}