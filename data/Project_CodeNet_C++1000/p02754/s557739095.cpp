#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = n / (a+b) * a + min(n%(a+b), a);
    cout << ans << "\n";
}
