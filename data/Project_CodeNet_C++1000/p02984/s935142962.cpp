#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> B(N, 0);

    ll Bmidsum = 0;
    rep(i, N - 1) Bmidsum += A[i];
    Bmidsum -= A[N - 1];

    ll Bjumpsum = 0;
    for (ll i = 0; i < N - 1; i += 2) {
        Bjumpsum += A[i];
    }
    Bjumpsum *= 2;

    B[0] = Bjumpsum - Bmidsum;

    for (ll i = 1; i < N - 1; i++) {
        B[i] = A[i - 1] * 2 - B[i - 1];
    }

    B[N - 1] = 2 * A[N - 1] - B[0];

    rep(i, N) cout << B[i] << " ";
    cout << endl;

    return 0;
}