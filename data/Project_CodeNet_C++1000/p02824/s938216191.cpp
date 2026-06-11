#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, V, P; cin >> N >> M >> V >> P;
    vector<ll> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());
    int ok = 0, ng = N;
    while (ng - ok != 1) {
        int med = (ng + ok) / 2;
        ll x = A[med] + M;
        ll MV = 0, count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > x) {
                MV += M;
                count++;
            } else if (count < P-1) {
                MV += M;
                count++;
            } else {
                MV += min(M, x - A[i]);
            }
        }
        if (count >= P || MV < M * V) {
            ng = med;
        } else {
            ok = med;
        }
    }
    cout << ok + 1 << endl;
}
