#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll output = 0;
    ll div = 1000000007;
    ll init = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                init++;
            }
        }
    }

    ll next = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = i + 1; j < 2 * N; j++) {
            if (A[i % N] > A[j % N]) {
                next++;
            }
        }
    }

    next -= init * 2;

    output = K * init % div;
    ll tmp = K * (K - 1) / 2;
    tmp %= div;
    tmp *= next;
    tmp %= div;
    output += tmp;
    output %= div;

    cout << output << endl;

    return 0;
}
