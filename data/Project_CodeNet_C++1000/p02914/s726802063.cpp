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
const int INF = 1001001001;
const ll LONGINF = 1001001001001001LL;
const ll MOD = 1000000007LL;

int main() {
    int N; scanf("%d", &N);
    vector<ll> A(N);
    ll sum = 0;
    for(int i=0; i<N; i++) scanf("%lld", &A[i]), sum ^= A[i];
    for(int i=0; i<N; i++) A[i] &= ~sum;

    ll ans = sum, r = 0;
    for(int k=59; k>=0; k--) {
        int j;
        for(j=r; j<N; j++) {
            if(A[j] >> k & 1) {
                swap(A[r], A[j]);
                break;
            }
        }

        if(j == N) continue;
        for(int i=0; i<N; i++) {
            if(i == r) continue;
            if(A[i] >> k & 1) A[i] ^= A[r];
        }
        r++;
    }

    /*
    for(int i=0; i<N; i++) fprintf(stderr, "%lld ", A[i]);
    fprintf(stderr, "\n");
    */

    ll x = 0;
    for(int i=0; i<N; i++) x ^= A[i];
    ans += (x << 1);
    cout << ans << endl;
    return 0;
}
