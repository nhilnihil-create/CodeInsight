#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
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
const int MOD = 1e9 + 7;

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
    }

    priority_queue<pair<ll, ll>> que;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) que.push(make_pair(B[i], i));
        if (B[i] < A[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll cnt = 0;
    while (!que.empty()) {
        pair<ll, ll> p = que.top();
        que.pop();
        ll b = p.first;
        int id = p.second;
        ll a = B[(N - 1 + id) % N];
        ll c = B[(1 + id) % N];
        if (b > a + c) {
            int low = b % (a + c);
            if (A[id] >= low) {
                if ((b - A[id]) % (a + c) == 0) {
                    cnt += (b - A[id]) / (a + c);
                    B[id] = A[id];
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                cnt += (b - low) / (a + c);
                B[p.second] = low;
                que.push(make_pair(low, id));
            }
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;

    return 0;
}
