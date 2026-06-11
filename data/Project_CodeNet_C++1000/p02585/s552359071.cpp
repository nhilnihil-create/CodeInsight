#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

#define mod         1000000007
#define pi          3.1415926535898
#define eps         1e-9


#define fast       ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define vt vector
#define ar array
#define fs          first
#define sc          second
#define pb         push_back
#define sp          printf(" ")
#define nl          '\n'
#define all(a) a.begin(),a.end()
#define unique(c) (c).resize(unique(all(c)) - (c).begin())
#define sz(x) (int)(x).size()
#define revsort(x) sort(all(x));reverse(all(x))

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define REP(i,start,end) for (int i = start; i <=end; i++)
#define RREP(i,end,start) for (int i=end; i>=start ;i--)
#define EACH(x, a) for (auto& x: a)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<double> vd;
typedef vector<vector<LL> > matrix;
typedef vector<vector<int> > graph;


 
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}

LL powm(LL x, LL y,LL m) {
    if (y==0) return 1;
    if (y==1) return x%m;
    if (y&1) return (x*(powm((x*x)%m,y/2,m)))%m;
    return powm((x*x)%m,y/2,m)%m;
}

LL inv(LL x, LL m) {
    return powm(x,m-2,m);
}

int add(int var1, int var2) {
    return (((((LL)(var1)) % mod + (LL)(var2)) % mod) + mod) % mod;
}


int mul(int var1, int var2) {
    return (((LL)(var1)) % mod * (LL)(var2)) % mod;
}

LL INF=4e18;

LL dp[5005][32];
LL nxt[5005][32];

void solve() {
    LL n,k;
    scanf("%lld %lld",&n,&k);
    vll p(n+1), c(n+1);
    REP (i, 1, n) scanf("%lld",&p[i]);
    REP (i, 1, n) scanf("%lld",&c[i]);

    REP (i,1,n) {
        dp[i][0] = c[p[i]];
        nxt[i][0] = p[i];
    }

    REP (i, 1, 31) REP(j, 1, n) {
        nxt[j][i] = nxt[nxt[j][i-1]][i-1];
        dp[j][i] = dp[j][i-1]+dp[nxt[j][i-1]][i-1];
    }

    LL ans = -INF;

    REP (i, 1, n) {
        LL ax = 0;
        LL cur = i;
        int low= max(n+1, k-n-1);

        REP(j, 0, 31) {
            if (((low-1)>>j)&1) {
                ax += dp[cur][j];
                cur = nxt[cur][j];
            }
        }

        REP(K, low, k) {
            ax += dp[cur][0];
            cur = nxt[cur][0];
            ans = max(ans, ax);
        }
    }

    REP (i, 1, n) {
        LL ax = 0;
        LL cur = i;
        REP(K, 1, min(n,k)) {
            ax += dp[cur][0];
            cur = nxt[cur][0];    
            ans = max(ans, ax);
        }
    }
    printf("%lld\n",ans);

}

int main() {
        solve();
}
