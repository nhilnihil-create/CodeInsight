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
    int x;
    cin >> x;
    if (x < 600)
        cout << "8";
    else if (x < 800)
        cout << "7";
    else if (x < 1000)
        cout << "6";
    else if (x < 1200)
        cout << "5";
    else if (x < 1400)
        cout << "4";
    else if (x < 1600)
        cout << "3";
    else if (x < 1800)
        cout << "2";
    else cout <<"1";

    return 0;
}