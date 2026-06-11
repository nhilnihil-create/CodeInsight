#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    string S;
    cin >> S;

    ll N = SZ(S);
    mat dp(N+1, vec(13, 0));
    S = "0" + S;
    
    if(S[1] == '?') {
        REP(i,0,10) dp[1][i] = 1;
    }
    else dp[1][S[1]-'0'] = 1;
    REP(i,2,N+1) {
        if(S[i] == '?') {
            REP(j,0,13) {
                REP(k,0,10) {
                    dp[i][(10*j+k)%13] += dp[i-1][j];
                    dp[i][(10*j+k)%13] %= MOD;
                }
            }
        }
        else {
            REP(j,0,13) {
                dp[i][(10*j+(S[i]-'0'))%13] += dp[i-1][j];
                dp[i][(10*j+(S[i]-'0'))%13] %= MOD;
            }
        }
    }

    PR(dp[N][5]);

    return 0;
}

/*



*/