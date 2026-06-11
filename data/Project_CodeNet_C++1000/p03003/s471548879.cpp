#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
#define INF 1LL<<60

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    ll mod = 1e9+7;
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    REP(i, N) cin >> S[i];
    REP(i, M) cin >> T[i];

    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 1));

    FOR(i, 1, N)
        FOR(j, 1, M) {
            if(S[i-1] == T[j-1])
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
            else
                dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mod) % mod;
        }    

    // cerr << "debug" << endl;
    // FOR(i, 0, N) {
    //     FOR(j, 0, M) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    cout << dp[N][M] << endl;

    return 0;
}