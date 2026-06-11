#include <bits/stdc++.h> 
using namespace std; 
#define for_(i, s, e) for (int i = s; i < e; i++)
#define for__(i, s, e) for (ull i = s; i < e; i++)
#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define endl "\n"


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<ll>> edges(n);
    for_(i, 0, n-1) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        edges[a-1].push_back(b-1);
    }

    ll ans = 0;
    for__(i, 1, n+1) ans += i * (n-i+1);
    for__(i, 0, n) for (auto j: edges[i]) {
        ans -= (i+1) * (n-j);
    }
    cout << ans << endl;

    return 0;
}