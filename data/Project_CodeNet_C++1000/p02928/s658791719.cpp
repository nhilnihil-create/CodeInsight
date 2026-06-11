#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
ll n, k;
const int Div = 1e9 + 7;
int main() {
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    int in = 0, between = 0;
    rep(i,n) rep(j,n) {
      if (v[i] > v[j]) {
        between++;
        if (i < j) in++;
      }
    } 
    ll ans = 0;
    ans += (in*k) % Div;
    ans += (k*(k-1)/2%Div) * between;
    ans %= Div;
    cout << ans << endl;
    return 0;
}