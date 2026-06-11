//2020-07-31
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define loopdesc(v, st, en) for (int v = st; v >= en; v--)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define P(x) cout << #x << " = { " << x << " }\n"
#define PI acos(-1)

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int M = 2e5 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    loop(i, 0, k)
    {
        if (b <= a)
            b *= 2;
        else if (c <= b)
            c *= 2;
        
        // else a*=2;
    }
    if (c > b && b > a)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}