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
    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(All(A));
    reverse(All(A));
    ll res = P;
    ll pool = A[P - 1];
    ll len = 1;
    ll ok = N - P - 1;
    for(int i = P; i < N; i++) {
        if(V <= P + ok) {
            if(A[P - 1] <= A[i] + M)
                res++;
            else {
                break;
            }
        } else {
            if(A[P - 1] <= A[i] + M &&
               (A[i] + M) * len - pool >= M * (V - (P + ok))) {
                res++;
            } else {
                break;
            }
        }
        pool += A[i];
        len++;
        ok--;
    }
    cout << res << endl;
    return 0;
}