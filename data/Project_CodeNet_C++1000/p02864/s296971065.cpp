#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <numeric>
#include <functional>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> H(N+1, 0);
    for (int n = 1; n <= N; ++n) cin >> H[n];
    
    if (N == K) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<ll>> DP(N+1, vector<ll>(N+1, INFLL));
    DP[0][0] = 0LL;
    for (int n = 1; n <= N; ++n) {
        for (int s = 1; s <= n; ++s) {
            ll Min = INFLL;
            for (int m = 0; m < n; ++m) {
                ll Tmp = DP[m][s-1] + max(H[n]-H[m], 0LL);
                if (Tmp < Min) Min = Tmp;
            }
            DP[n][s] = Min;
        }
    }
    ll Res = INFLL;
    for (int n = 1; n <= N; ++n) {
        ll Tmp = DP[n][N-K];
        if (Tmp < Res) Res = Tmp;
    }
    cout << Res << endl;

    return 0;
}
