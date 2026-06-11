/* Simplicity and Goodness */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> indexed_set;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B)
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define rep(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int maxN = 2e5+2;


void solve()
{
    int h, w, a, b;
    scanf("%d%d%d%d", &h, &w, &a, &b);

    char x = '0', y = '1';

    rep(i, 0, h)  {
        if(i == b) swap(x, y);
        cout << string(a, x) << string(w - a, y) << '\n';
    }
}

int main()
{
    int t = 1;
    // scn(t);
    while(t --) {
        solve();
    }
    return 0;
}