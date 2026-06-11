#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;


int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> x(N, vector<int>(0)), y(N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        vector<int> empty(A[i]);
        x[i] = empty;
        y[i] = empty;
        for (int j = 0; j < A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    int ans = 0;
    for (int tmp = 0; tmp < (1 << N); tmp++) {
        bitset<15> b(tmp);
        int ok_tmp = 1;
        for (int i = 0; i < N; i++) {
            if (b.test(i)) {
                for (int j = 0; j < A[i]; j++) {
                    if (y[i][j] == 1 && !(b.test(x[i][j]))) {
                        ok_tmp *= 0;
                        break;
                    }
                    else if (y[i][j]==0 && b.test(x[i][j])) {
                        ok_tmp *= 0;
                        break;
                    }
                }
            }
            if (ok_tmp == 0) {
                break;
            }
        }
        if (ok_tmp) {
            int alt = b.count();
            ans = max(ans, alt);
        }
    }
    cout << ans << endl;
}
