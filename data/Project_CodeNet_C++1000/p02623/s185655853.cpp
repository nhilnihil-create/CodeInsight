#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N, M, K;
    ll a, b;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    REP(i, N){
        cin >> a;
        A[i] = i == 0 ? a: min(1e9 + 100, A[i-1] + a);
    }
    REP(i, M){
        cin >> a;
        B[i] = i == 0 ? a: min(1e9 + 1000, B[i-1] + a);
    }
    ll ans = 0;
    REP(i, N + 1){
        ll tmp = i == 0 ? K: K - A[i-1];
        if (tmp < 0) continue;
        auto iter = upper_bound(B.begin(), B.end(), tmp);
        ans = max(ans, i + iter - B.begin());

    }
    cout << ans << endl;

    return 0;
}