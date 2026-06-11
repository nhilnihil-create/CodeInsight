#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 300+5;

int dp[maxn][maxn][maxn]; // position, k, previous height index
int h[maxn]; // input height, totheight
vector<int> tot;
signed main(){
    IOS();
    int n, K; cin>>n>>K;
    for (int i = 0; i<n; i++){
        cin>>h[i+1]; tot.pb(h[i+1]);
    }
    tot.pb(0);
    SORT_UNIQUE(tot);
    for (int i = 0; i<n; i++) {
        h[i+1] = lower_bound(ALL(tot),h[i+1]) - tot.begin();
        bug(i,h[i+1]);
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][K][0] = 0;
    int m = tot.size();
    for (int i = 1; i<=n; i++) {
        for (int k = 0; k<=K; k++) {
            MN(dp[i][k][h[i]] , dp[i-1][k][ h[i-1] ] + max(tot[h[i]]-tot[h[i-1]],0ll));

            for (int ph = 0ll; ph < m; ++ph) {
                MN(dp[i][k][h[i]], dp[i-1][k][ph] + max(tot[h[i]]-tot[ph],0ll));
                MN(dp[i][k][ph] , dp[i-1][k+1][ ph ]);
                MN(dp[i][k][ph] , dp[i-1][k+1][ h[i-1] ] + max(tot[ph] - tot[h[i-1]], 0ll));
            }
        }
    }

    ll re = 0x3f3f3f3f3f3f3f3f;
    for (int k = 0; k<=K; k++) {
        for (int ph = 0; ph < m; ++ph) MN(re, dp[n][k][ph]);
    }
    cout<<re<<endl;

}
