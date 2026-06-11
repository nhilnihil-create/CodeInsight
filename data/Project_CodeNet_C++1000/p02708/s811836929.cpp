#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define PI 3.14159265358979323846
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pll pair<long long, long long>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9+7;

// グローバル変数（入力）
ll n,k;

void input() { 
  cin >> n >> k;
}

void solve() {
  vll rl(n+1),ru(n+1);
  rl[0]=0;ru[0]=n;
  rep1(i,n){
    rl[i]=rl[i-1]+i;
    ru[i]=ru[i-1]+(n-i);
  }
  ll ans=0;
  for (ll i=k-1; i<=n; i++){
    ans += (ru[i]-rl[i]+1)%MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main() {
  input();
  solve();
  return 0;
}
