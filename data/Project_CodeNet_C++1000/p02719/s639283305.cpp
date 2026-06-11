#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    if (n > k) {
        ll cnt = n / k;
        n -= cnt * k;
    }
    cout << min(n, k - n);
    return 0;
}
