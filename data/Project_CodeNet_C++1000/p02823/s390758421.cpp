#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table

#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()

using namespace std;
// using namespace __gnu_pbds;


typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = (int) 1e5 + 10;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll d = b - a >> 1;
    if(a % 2 != b % 2) {
        ll go_to_1 = ((a - 1) + 1) + (b - a) / 2;
        ll go_to_2 = ((n - b) + 1) + (b - a) / 2;
        d = min(go_to_1, go_to_2);
    }
    cout << d << '\n';
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    // int t; cin >> t; while(t--)
    solve();
    cout.flush();
    return 0;
}