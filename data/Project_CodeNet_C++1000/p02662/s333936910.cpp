#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
const ll INF = 1e18;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, S;
    cin >> n >> S;

    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll mod = 998244353;    
    vector<vector<ll> > dp(n+1, vector<ll>(S+1, 0));
    dp[0][0] = 1;

    rep(i, n) {

        rep(j, S+1) {
            // 選ばない
            dp[i+1][j] += dp[i][j] * 2;
            dp[i+1][j] %= mod;

            //　選ぶ
            if (j-A[i] >= 0) {
                dp[i+1][j] += dp[i][j-A[i]];
                dp[i+1][j] %= mod;
            }
        }
    }

    ll res = dp[n][S];
    put(res);

}
signed main(){ Main();return 0;}