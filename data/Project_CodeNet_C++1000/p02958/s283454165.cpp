#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll norma[n];
    ll p[n];
    for (ll i = 0; i < n;i++){
        cin >> p[i];
        norma[i] = i + 1;
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (p[i] != norma[i]) cnt++;
    }
    if (cnt == 0 || cnt == 2) cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
