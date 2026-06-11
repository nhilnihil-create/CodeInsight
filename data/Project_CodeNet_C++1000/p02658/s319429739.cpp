#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    long long maxn = 1000000000000000000;
    long long ans = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] > maxn / ans) {
            cout << -1 << endl;
            return 0;
        } else {
            ans *= A[i];
        }
    }

    cout << ans << endl;

    return 0;
}
