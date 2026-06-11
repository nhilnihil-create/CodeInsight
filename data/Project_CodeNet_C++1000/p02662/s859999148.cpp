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
#include <iomanip>
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

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    ll N, S, mod = 998244353;
    cin >> N >> S;
    vector<ll> A(N+1);
    REP(i, N) cin >> A[i+1];
    vector< vector<ll> > dp(N + 1, vector<ll>(S+1, 0));
    dp[0][0] = 1;
    FOR(i, 1, N) {
        REP(j, S+1) {
            if(j - A[i] >= 0)   
                dp[i][j] += 2 * dp[i-1][j] + dp[i-1][j-A[i]];
            else
                dp[i][j] += 2 * dp[i-1][j];
            dp[i][j] %= mod;
        }
    }

    // FOR(i, 0, N) {
    //     REP(j, S+1) cerr << dp[i][j] << " ";
    //     cerr << endl;
    // }
    cout << dp[N][S] << endl;
    return 0;
}