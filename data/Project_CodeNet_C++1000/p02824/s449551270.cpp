#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M, V, P; cin >> N >> M >> V >> P;
    vector<ll> A(N); for (auto &x : A) cin >> x;
    sort(A.begin(), A.end(), greater<ll>());
    ll ok = 0, ng = N;
    while (ng - ok != 1) {
        ll med = (ok + ng) / 2;
        ll obj = A[med];
        ll temp = 0;
        bool flag = true;
        int t = 0;
        for (int i = 0; i < N; i++) {
            if (t < P-1 || obj + M < A[i]) {
                temp += M;
                t++;
            } else {
                temp += min(obj + M - A[i], M);
            }
        }
        if (temp >= M * V && t < P) ok = med;
        else ng = med;
    }
    cout << ok + 1 << endl;
}
