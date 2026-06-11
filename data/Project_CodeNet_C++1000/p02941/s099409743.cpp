//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int ll
#define xx first
#define yy second
#define pb push_back
#define all(x) begin(x), end(x)
#define OUT(x) { cout << x; exit(0); }
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const db eps = 1e-9;
const db pi = acos(-1.0);
const db dinf = 1e250;
const ll INF = (ll)(2e18);
const int inf = (int)(1e9 + 7);
//------------------------------------------//

vi a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cin.tie(0);

#ifdef _MY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    a = vi(n);
    b = vi(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;

    priority_queue<pii> s;
    for (int i = 0; i < n; ++i)
        s.push({ b[i], i });
    
    int res = 0;
    int p = 0;
    while(s.size())
    {
        int i = s.top().yy;
        int cur = (b[i] - a[i]) / (b[(i + 1) % n] + b[(i - 1 + n) % n]);
        res += cur;
        b[i] -= a[i];
        b[i] %= b[(i + 1) % n] + b[(i - 1 + n) % n];
        b[i] += a[i];
        s.pop();
        if (b[i] < a[i]) OUT(-1);
        if (b[i] > a[i]) s.push({ b[i], i });
        if (b[i] > a[i] && cur == 0) OUT(-1);
    }

    cout << res;


    return 0;
}