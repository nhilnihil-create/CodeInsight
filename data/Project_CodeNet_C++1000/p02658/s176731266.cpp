#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int zero = 0;

    for (int i = 0; i < N; i++) {
        if (A.at(i) == 0) zero++;

        if (0 < zero) {
            cout << "0" << endl;
            return 0;
        }
    }

    int64_t ans = 1;

    for (int i = 0; i < N; i++) {
        if (A.at(i) <= 1000000000000000000/ans) {
            ans *= A.at(i);
        }
        else {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << ans << endl;
}