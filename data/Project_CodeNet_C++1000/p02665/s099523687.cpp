#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N + 1), B(N + 1), C(N + 1), D(N + 1);
    for (int i = 0; i < N + 1; i++) {
        cin >> A.at(i);
        D.at(0) += A.at(i);
    }
    for (int i = 0; i < N; i++) {
        D.at(i + 1) = D.at(i) - A.at(i);
    }
    if (A.at(0) != 0) {
        if (A.at(0) != 1 || D.at(0) != 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    B.at(0) = 1;
    C.at(0) = 1;
    bool can = true;
    for (int i = 0; i < N; i++) {
        if (C.at(i) * 2 < A.at(i + 1)) {
            can = false;
        }
        if (C.at(i) * 2 <= D.at(i + 1)) {
            B.at(i + 1) = C.at(i) * 2;
            C.at(i + 1) = C.at(i) * 2 - A.at(i + 1);
        }
        else {
            B.at(i + 1) = D.at(i + 1);
            C.at(i + 1) = D.at(i + 1);
        }
    }
    if (!can) {
        cout << -1 << endl;
    }
    else {
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += B.at(i);
        }
        cout << ans + A.at(N) << endl;
    }
}