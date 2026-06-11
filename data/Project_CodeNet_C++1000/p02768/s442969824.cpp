#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
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
void init_combination(){
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % MOD;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], MOD - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % MOD;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % MOD;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ret = 1;
    for(ll i = 0; i < b; i++) {
        ret *= (a - i);
        ret %= MOD;
        ret *= beki(i + 1, MOD - 2);
        ret %= MOD;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
  init_combination();
  ll a, b, n;
  cin >> n >> a >> b;
  ll ans = beki(2, n) - 1;
  cout << (2*MOD + ans - combination(n, a) - combination(n, b)) % MOD << endl;
  return 0;
}