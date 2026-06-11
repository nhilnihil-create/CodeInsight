#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  998244353
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

ll beki(ll a, ll b){
    a %= MOD;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % MOD;
    if(b % 2 == 1){
        ans = ans * a % MOD;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  map<ll,ll> d;
  rep(i,n) {
    ll a;
    cin >> a;
    if(i==0&&a!=0){
      puts("0");
      return 0;
    }
    d[a]++;
  }
  ll ans = 1;
  if (d[0] != 1) ans = 0;
  for (ll i = 1; i < n; i++){
    ans *= beki(d[i-1], d[i])%MOD;
    ans %= MOD;
  }
  while(ans<0){
    ans += MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;

}