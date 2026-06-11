#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
    
    sort(ALL(A));
    reverse(ALL(A));
    sort(ALL(F));
    ll left = 2000000000000, right = -1;
    while (left - right > 1) {
        ll mid = (right + left) / 2;
        ll cnt = 0;
        rep(i, N) {
            cnt += max(0LL, A[i] - mid / F[i]);
        }
        if (cnt > K) right = mid;
        else left = mid;
    }
    cout << left << "\n";
    return 0;
}
