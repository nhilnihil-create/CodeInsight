#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int siz = 2e5 + 10;
const int SIZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e12;
const string file = "2";



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//    freopen ((file + ".inp").c_str(), "r", stdin);
//    freopen ((file + ".out").c_str(), "w", stdout);

    int n;
    cin >> n;

    vector <int> pos, neg;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        pos.push_back(x + y);
        neg.push_back(x - y);
    }

    sort (all(pos));
    sort (all(neg));

    cout << max(pos.back() - pos.front(), neg.back() - neg.front());

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    return 0;
}
