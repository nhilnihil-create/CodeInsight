#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>

#include<deque>
#define pi 3.141592653589793238
#include<chrono>

#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
#define db double
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n, s;
        cin >> n >> s;
        vector<ll> v(n);
        for(i = 0 ; i < n ; i++){
            cin>> v[i];
        }
        ll mod = 998244353;
 
        ll dp[3001][3001] = { 0 };
        dp[0][0] = 1;
        for(i = 0 ; i < n; i++){
            for(j = 0; j <= s; j++){
                dp[i + 1][j] += 2 * dp[i][j];
              dp[i + 1][j] %= mod;
            }
            for(j = v[i]; j <= s; j++){
                dp[i + 1][j] += dp[i][j - v[i]];
                dp[i + 1][j] %= mod;
            }
        }
        cout << dp[n][s] % mod;
    }
    
    return 0;
}
