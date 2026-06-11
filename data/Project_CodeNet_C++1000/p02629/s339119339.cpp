#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;

    string ans = "";

    while (n > 0) {
        --n;
        ll x = n%26;
        ans += 'a'+x;
        n /= 26;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}