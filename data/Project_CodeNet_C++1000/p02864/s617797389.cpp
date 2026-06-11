#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int i=(first);i<(last);++i){cout<<#a<<"["<<i<<"] = "<<(a)[i]<<endl;}
#define PRINTP(p)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#p<<" = ("<<(p.first)<<", "<<(p.second)<<")"<<endl;
#define PRINTI(a,i)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<#i<<"] = "<<#a<<"["<<(i)<<"] = "<<(a)[i]<<endl;
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#define PRINTP(p)
#define PRINTI(a,i)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    constexpr ll N_MAX = 300;
    constexpr ll H_MAX = 1000000000;
    constexpr ll INF = N_MAX * H_MAX;

    ll N, K;
    cin >> N >> K;
    vector<ll> H(N + 1, 0);
    FOR(i, 1, N + 1) cin >> H[i];

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(K + 1, INF)));
    REP(j, N + 1) {
        REP(k, K + 1) {
            dp[N][j][k] = 0;
        }
    }
    RFOR(i, 0, N) {
        REP(j, i + 1) {
            FOR(k, 0, K + 1) {
                dp[i][j][k] = dp[i + 1][i + 1][k] + max(H[i + 1] - H[j], 0ll);
                if (k > 0) {
                    amin(dp[i][j][k], dp[i + 1][j][k - 1]);
                }
            }
        }
    }
    cout << dp[0][0][K] << endl;

    return 0;
}