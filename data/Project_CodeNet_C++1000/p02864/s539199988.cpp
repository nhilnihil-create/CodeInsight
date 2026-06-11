// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

ll dp[310][310][310];
int main() {
    int N, K; cin >> N >> K;
    vector<ll> H(N);
    for(int i=0; i<N; i++) cin >> H[i];

    vector<ll> M = H;
    M.emplace_back(0);
    sort(M.begin(), M.end());
    M.erase(unique(M.begin(), M.end()), M.end());

    fill(dp[0][0], dp[N+1][0], LONGINF);
    dp[0][0][0] = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=K; j++) {            
            ll opt_less = LONGINF;
            for(int k=0; k<(int)M.size(); k++) {
                chmin(opt_less, dp[i][j][k]);
                chmin(dp[i+1][j+(M[k]!=H[i])][k], opt_less);
                if(k+1<(int)M.size()) opt_less += M[k+1] - M[k];
            }

            ll opt_more = LONGINF;
            for(int k=(int)M.size()-1; k>=0; k--) {
                chmin(opt_more, dp[i][j][k]);
                chmin(dp[i+1][j+(M[k]!=H[i])][k], opt_more);                
            }
        }
    }

    ll ans = LONGINF;
    for(int j=0; j<=K; j++) {
        for(int k=0; k<(int)M.size(); k++) {
            chmin(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}
