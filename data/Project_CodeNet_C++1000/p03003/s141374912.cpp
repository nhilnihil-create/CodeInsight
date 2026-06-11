#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef string str;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define pb(x)                       push_back(x)
#define pf(x)                       push_front(x)
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e5 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll dp[MAXN] , a[MAXN] , b[MAXN] , k[MAXN];

int main(){

    ll n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        dp[i] = 1;
    }
    k[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            k[j] = k[j - 1];
            if(a[i] == b[j]){
                k[j] = (k[j] + dp[j - 1]) % MOD;
            }
        }
        for(int j = 1; j <= m; j++){
            dp[j] = (dp[j] + k[j]) % MOD;
        }
    }
    cout << dp[m];

}
