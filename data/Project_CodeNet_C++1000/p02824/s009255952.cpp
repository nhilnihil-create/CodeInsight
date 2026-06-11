#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

ll N, M, V, P;
bool C(int mid, const vector<ll> &A) {
    // debug(mid);
    if (mid <= P - 1) {
        return true;
    } else if (A[mid] + M < A[P - 1]) {
        return false;
    } else {
        ll sum = 0;
        for (int i = P - 1; i < mid; i++) {
            sum += A[mid] + M - A[i];
        }
        for (int i = mid + 1; i < N; i++) {
            sum += M;
        }
        // cout << mid << ": " << sum << endl;
        return sum >= M * (V - P);
    }
}

int main() {
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end(), greater<ll>());
    int ng = N;
    int ok = 0;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (C(mid, A)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok + 1 << endl;
}
