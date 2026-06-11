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
 
int main() {
    int N, K; scanf("%d%d", &N, &K);
    vector<int> P(N);
    for(int i=0; i<N; i++) scanf("%d", &P[i]), P[i]--;
    vector<int> C(N);
    for(int i=0; i<N; i++) scanf("%d", &C[i]);

    ll ans = -LONGINF;
    vector<bool> visited(N);
    for(int i=0; i<N; i++) {
        if(visited[i]) continue;
        vector<int> cycle;
        int x = i;
        while(true) {
            visited[x] = true;
            cycle.emplace_back(C[x]);
            x = P[x];
            if(x == i) break;
        }

        int M = cycle.size();
        ll cost_w = accumulate(cycle.begin(), cycle.end(), 0LL);
        vector<ll> pref(M+1, -LONGINF);
        for(int i=0; i<M; i++) {
            ll sum = 0;
            for(int j=0; j<M; j++) {
                int p = (i+j)%M;
                sum += cycle[p];
                chmax(pref[j+1], sum);
            }
        }

        for(int k=1; k<=M; k++) {
            if(k > K) continue;
            int d = (K - k) / M;            
            chmax(ans, max(0LL, cost_w * d) + pref[k]);
        }
    }
    cout << ans << endl;
    return 0;
}
