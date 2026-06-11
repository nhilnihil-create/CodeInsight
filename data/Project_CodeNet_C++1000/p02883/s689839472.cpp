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

bool check(ll score, ll K, vector<ll> &A, vector<ll> &F) {
    ll N = A.size();
    rep(i, N) {
        K -= max(0LL, A[i] - score / F[i]);
        if(K < 0)
            return false;
    }
    return true;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> F(N);
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    rep(i, N) cin >> F[i];

    if(sum <= K) {
        cout << 0 << endl;
        return 0;
    }
    sort(All(A));
    sort(F.rbegin(), F.rend());
    ll lb = 0, ub = LINF;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(check(mid, K, A, F)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << ub << endl;
    return 0;
}