#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DP[2100][2100];
ll SUM[2100][2100];

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N+1);
    vector<ll> T(M+1);
    REP(i,N){
        cin >> S[i];
    }
    REP(i,M){
        cin >> T[i];
    }

    S[N] = -10000;
    T[M] = -100;

    //REP(i,2100) REP(j,2100) DP[i][j] = -1e12;
    DP[0][0] = 1;

    REP(i,N+1){
        ll s = S[i];
        REP(j,M+1){
            ll t = T[j];

            SUM[i][j] = DP[i][j];
            if(i > 0) SUM[i][j] += SUM[i-1][j];
            if(j > 0) SUM[i][j] += SUM[i][j-1];
            if(j > 0 && i > 0) SUM[i][j] += MOD - SUM[i-1][j-1];
            SUM[i][j] %= MOD;

            if(s == t){
                DP[i+1][j+1] += SUM[i][j];
                DP[i+1][j+1] %= MOD;
            }

            //DP[i][j+1] += DP[i][j];
            //DP[i][j+1] %= MOD;

        }
    }

    ll ans = 0;
    ans = SUM[N][M] % MOD;

    cout << ans << endl;

    return 0;
}
