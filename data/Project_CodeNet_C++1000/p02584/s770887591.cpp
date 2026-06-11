#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size()
#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define forn(i, n) for (int i = 1; i <= n; i++)
#define ford(i, n) for (int i = n; i >= 0; i--)
#define REP(i, a, n) for (int i = a; i < n; i++)
#define foreach(itr, c) for (__typeof((c).begin(), (c).end()) itr = c.begin(); itr != c.end(); itr++)
#define fill(a, b) memset(a, b, sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<char> vs;
typedef vector<pi> vpi;

using namespace std;

int main()
{
    fast();
    ll X, K, D;

    cin >> X >> K >> D;

    if (X < 0)
    {
        X = -X;
    }

    if (K <= X / D)
    {
        cout << X - (K * D);
    }
    else
    {
        K -= X / D;
        if (K % 2 == 0)
        {
            cout << X % D;
        }
        else
        {
            cout << D - X % D;
        }
    }
}