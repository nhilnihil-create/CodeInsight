#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<long long> cnt(100001);
    int maxD = 0;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        if (i == 0 && d != 0) {
            cout << 0 << endl;
            return 0;
        }
        cnt[d]++;
        maxD = max(maxD, d);
    }

    if (cnt[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    long long res = 1;
    for (int i = 1; i <= maxD; i++) {
        if (cnt[i] == 0) {
            cout << 0 << endl;
            return 0;
        }

        for (int j = 0; j < cnt[i]; j++) {
            res = res * cnt[i - 1] % MOD;
        }
    }

    cout << res << endl;
    return 0;
}
