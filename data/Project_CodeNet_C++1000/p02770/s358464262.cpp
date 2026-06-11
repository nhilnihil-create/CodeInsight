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
    int K, Q; scanf("%d%d", &K, &Q);
    vector<ll> D(K);
    for(int i=0; i<K; i++) scanf("%lld", &D[i]);

    while(Q--) {
        ll N, X, M; scanf("%lld%lld%lld", &N, &X, &M);
        vector<ll> E = D;
        for(auto &e : E) e %= M;
        ll ans = N - 1, mod = (N - 1) % K, div = (N - 1) / K;

        // equal
        for(int i=0; i<K; i++) {
            if(E[i] == 0) ans -= div + (i < mod);
        }

        // less
        ll sum = 0;
        for(int i=0; i<K; i++) sum += E[i];

        ll a = X + sum * div, b = X;
        for(int i=0; i<mod; i++) a += E[i];
        ans -= a / M - b / M;

        printf("%lld\n", ans);
    }
    return 0;
}
