#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll sum = 0;
    rep(i, N) {
        if(i % 2 == 0) {
            sum += 2 * A[i];
        } else {
            sum -= 2 * A[i];
        }
    }
    vector<ll> res(N);
    res[0] = sum / 2;
    for(int i = 1; i < N; i++) {
        res[i] = 2 * (A[i - 1] - res[i - 1] / 2);
    }
    rep(i, N) { cout << res[i] << (i == N - 1 ? "\n" : " "); }
    return 0;
}