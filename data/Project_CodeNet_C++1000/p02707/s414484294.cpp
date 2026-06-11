#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define out(x) #x << " = " << x
#define yn(x) ((x) ? "YES" : "NO")
#define el "\n"
using namespace std;
typedef pair <int, int> ii;

const ll siz = 2e5 + 10;
const ll SIZ = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll maxx = 2e9;
const ll MAXX = 1e18;

int a[siz];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen ("IN_4.INP", "r", stdin);
//    freopen ("OUT_4.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << el;
    return 0;
}
