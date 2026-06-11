#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


class BinaryIndexedTree {
    int N;
    vector<ll> data;
public:
    BinaryIndexedTree(int N) : N(N) {
        data.resize(N + 1, 0);
    }

    ll sum(int k) {
        ll res = 0;
        for (; k > 0; k -= k & -k) {
            res += data[k];
        }
        return res;
    }

    void add(int k, ll x) {
        for (; k <= N; k += k & -k) {
            data[k] += x;
        }
    }
};


int main() {
    int N;
    cin >> N;
    BinaryIndexedTree bit(210000);
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; ++i) {
        A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }

    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        int a = A[i];
        ans += i - bit.sum(a+1);
        bit.add(a+1, 1);
    }
    cout << ans << '\n';
}

