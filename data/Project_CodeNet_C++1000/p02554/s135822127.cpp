#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi acos(-1.0)
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int mod = 1e9+7;
const int N = 1e6+7;
int n;
ll dp[N][4];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
#endif
    fastIO;
    cin >> n;
    dp[0][0]=1;
    forw(i,1,n+1) {
        dp[i][0]=8*dp[i-1][0]%mod;
        dp[i][1]=(dp[i-1][0]+9*dp[i-1][1])%mod;
        dp[i][2]=(9*dp[i-1][2]+dp[i-1][0])%mod;
        dp[i][3]=(dp[i-1][1]+dp[i-1][2]+10*dp[i-1][3])%mod;
    }
    cout << dp[n][3];
    return 0;
}
