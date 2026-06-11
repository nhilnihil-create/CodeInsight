#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int INF = 1e9;
const int MAX = 2500;

int main() {
    ll x;
    cin >> x;
    ll ans = 0, a = 100;
    while(a < x) {
        a += a / 100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}