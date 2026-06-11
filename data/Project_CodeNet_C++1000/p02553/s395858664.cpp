#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define ull unsigned long long
#define ld long double
#define uint unsigned int
struct debug {
~debug() {cerr << "\n";}template<class C> debug& operator<<(C c) {cerr << c;return *this;}
};
#define var(x) " [" << #x << ": " << x << "]"

constexpr ll INF=-1e18-5;
ll a, b, c, d, ans=INF;

void solve() {
    cin >> a >> b >> c >> d;
    for(int x:{a, b}) {
        for(int y:{c, d}) {
            ans=max(ans, (ll)x*y);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}