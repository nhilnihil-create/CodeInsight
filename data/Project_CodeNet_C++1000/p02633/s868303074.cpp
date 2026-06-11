#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table

#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back

using namespace std;
// using namespace __gnu_pbds;


typedef long long int ll;
typedef pair<int, int> pii;

const int N = (int) 8080;
const double PI = acos(-1);
const double E = 1e-5;

void solve() {
    int d; cin >> d;
    double dt = d * PI / 180.0;
    double angle = dt;
    int ans = 1;
    double x = 0, y = 1;
    while(true) {
        if(abs(x) <= E && abs(y) <= E) break;
        x += sin(angle);
        y += cos(angle);
        angle += dt;
        ++ans;
    }
    cout << ans << endl;
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    solve();
    cout.flush();
    return 0;
}