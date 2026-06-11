/* Simplicity and Goodness */
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;

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

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int N = 1e3+2;

/*  dp[i][j] : minimum cost rerquired to put the monster's health to j 
               using first i spells.
*/

const int H = 1e4+2;

int dp[N][H];

void solve()
{
    int h, n;
    scn(h); scn(n);

    pair<int, int> p[n+1];

    rep(i, 1, n+1)
    scn(p[i].F), scn(p[i].S);

    rep(i, 0, H)
    dp[0][i] = 1e9;

    dp[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=h; j++) {
            if(j == 0) {
                dp[i][0] = 0;
            } else if(p[i].F <= j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j - p[i].F] + p[i].S);
            } else {
                dp[i][j] = min(dp[i-1][j], p[i].S);
            }
            // Using the same spell multiple times.
            if(p[i].F <= j) {
                dp[i][j] = min(dp[i][j], dp[i][j - p[i].F] + p[i].S);
            }
        }
    }

    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=h; j++) {
    //         cout << dp[i][j] << ' ';
    //     }puts("");
    // }

    prin(dp[n][h]);
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