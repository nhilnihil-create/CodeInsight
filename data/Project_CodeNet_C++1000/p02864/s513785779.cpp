//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include<climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pi;
typedef vector<pair<ll, ll>> vpi;

//const long long INF = 1LL << 55;

#define itn ll
#define endl '\n'
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(ll i = 0;i < n;i++)
#define rep(i,n) for(ll i = 0;i < n;i++)
#define flush fflush(stdout)
#define rrep(i,n) for(ll i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define ioboost cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, ll mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

ll dp[310][310]; // rightest, size
int main(void){
    ll n,k;cin >> n >> k;
    vector<ll> h(n+1,0);
    rep(i,n)cin >> h[i+1];

    const long long INF = 1001001001000;
    for (int i = 0; i < 310; ++i)
    {
        for (int j = 0; j < 310; ++j)
        {
            dp[i][j] = INF;
        }
    }

    //dp[1][0] = 0;
    dp[0][0] = 0;
    for(int x = 1;x <= n;x++){ // 選ぶ集合のうち最も右側のもの
        for(int y = 1;y <= x;y++){ //　いくつ選んだか
            ll _min = INF;
            for(int z = 0;z < x;z++){
                mins(_min , dp[z][y - 1] + max(0ll,h[x] - h[z]));
            }
            dp[x][y] = _min;
        }
    }
    ll ans = INF;
    for(int i = 0;i < 310;i++)mins(ans,dp[i][n - k]);
    cout << ans << endl;

}