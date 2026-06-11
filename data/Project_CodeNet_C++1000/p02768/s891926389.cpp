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

int me(int x, int n)
{
    int res = 1;
    while(n) {
        if(n & 1)
            res = (1LL * res * x) % mod;
        x = (1LL * x * x) % mod;
        n >>= 1;
    }
    return res;
}

int fac[N], inv[N];

void fact() 
{
   fac[0] = 1;
   rep(i, 1, N) {
      fac[i] = (1LL * fac[i-1] * i) % mod;
   }

   inv[N-1] = me(fac[N-1], mod-2);
   for(int i=N-1; i>0; i--) {
      inv[i-1] = (1LL * inv[i] * i) % mod;
   }
}

void solve()
{
    fact();

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    int total = me(2, n);
    total = (total - 1 + mod) % mod;

    int da = 1;

    for(int i=n; i>=(n-a+1); i--) {
        da = (1LL * da * i) % mod;
    }

    da = (1LL * da * inv[a]) % mod;

    int db = 1;

    for(int i=n; i>=(n-b+1); i--) {
        db = (1LL * db * i) % mod;
    }

    db = (1LL * db * inv[b]) % mod;

    total = (total - da + mod) % mod;
    total = (total - db + mod) % mod;

    lprin(total);
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