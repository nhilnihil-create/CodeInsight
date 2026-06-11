#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double eps = 1e-9;
const ll N = 1e6 + 10;
const int M = 1e9 + 7;
const ll MAX = 1e18 + eps;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

ll solvex(ll n) {
    return ((ll) (sqrt(8 * n + 1) + eps) - 1) / 2;
}

int main() {
    ll n;
    cin >> n;
    map<ll, int> pf;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            pf[i]++;
            n /= i;
        }
    }
    if (n > 1)
        pf[n]++;
    ll ans = 0;
    for (auto x: pf) {
        ans += solvex(x.second);
    }
    cout << ans << endl;
}