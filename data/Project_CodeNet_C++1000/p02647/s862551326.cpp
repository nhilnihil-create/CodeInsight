#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N+2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    while (K--) {
        vector<ll> B(N+2, 0);
        for (int i = 1; i <= N; i++) {
            ll a = max(1LL, i-A[i]), b = min(N, i+A[i])+1;
            B[a]++, B[b]--;
        }
        bool flag = 0;
        for (int i = 1; i <= N+1; i++) {
            B[i] += B[i-1];
            if (A[i] != B[i]) {
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
        swap(A, B);
    }
    for (int i = 1; i <= N; i++) {
        cout << A[i];
        if (i == N) {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
}