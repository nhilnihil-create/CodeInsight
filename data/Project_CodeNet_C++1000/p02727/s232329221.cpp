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
const int N = 2e5+2;

void solve()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vi red(a), green(b);
    multiset<int> colorless;

    rep(i, 0, a)
    scn(red[i]);

    rep(i, 0, b)
    scn(green[i]);

    rep(i, 0, c) {
        int val;
        scn(val);
        colorless.insert(val);
    }

    multiset<int> best;

    sort(red.begin(), red.end(), greater<int>());
    sort(green.begin(), green.end(), greater<int>());

    rep(i, 0, x)
    best.insert(red[i]);

    rep(i, 0, y)
    best.insert(green[i]);

    while(1) {
        int here = *best.begin();

        auto j = colorless.upper_bound(here);
        if(j == colorless.end())
            break;

        int val = *j; colorless.erase(colorless.find(val));

        best.erase(best.find(here)); best.insert(val);
    }

    ll sum = 0;

    for(auto x : best) {
        sum += 1LL * x;
    }

    lprin(sum);
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