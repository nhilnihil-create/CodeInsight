#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i, n+1) a[i] = 0;
    rep(i, n) for (ll j = 0; j <= n; j += (i+1)) a[j]++;
    ll ans = 0;
    rep(i, n+1) ans += i * a[i];
    cout << ans << endl;
    return 0;
}