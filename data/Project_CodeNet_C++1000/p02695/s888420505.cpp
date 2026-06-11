#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

struct val {
    ll a;
    ll b;
    ll c;
    ll d;
};
ll recursive(vector<ll> &A, ll i, ll M, vector<val> &vs) {
    if (i == A.size() - 1) {
        ll total = 0;
        for (auto v : vs) {
            if (A[v.b] - A[v.a] == v.c) {
                total += v.d;
            }
        }
        return total;
    }
    ll maxscore = 0;
    for (ll j = A[i]; j <= M; j++) {
        A[i + 1] = j;
        maxscore = max(maxscore, recursive(A, i + 1, M, vs));
    }
    return maxscore;
}

int main() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<val> vs(Q);
    for (ll i = 0; i < Q; i++) {
        val v;
        cin >> v.a >> v.b >> v.c >> v.d;
        v.a--;
        v.b--;
        vs[i] = v;
    }

    vector<ll> A(N);
    ll maxval = 0;
    for (ll j = 1; j <= M; j++) {
        A[0] = j;
        maxval = max(maxval, recursive(A, 0, M, vs));
    }
    print(maxval);
}
