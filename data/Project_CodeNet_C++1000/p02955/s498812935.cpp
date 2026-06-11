#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    return res;
}

int main() {
    int N, K;  cin >> N >> K;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    for (int d : divisors(sum)) {
        bool ok;
        vector<int> r(N);
        int allsum_r = 0;
        for (int i = 0; i < N; ++i) {
            r[i] = A[i] % d;
            allsum_r += r[i];
        }
        sort(r.begin(), r.end());
        int sum_r = 0;
        for (int i = 0; i < N; ++i) {
            sum_r += r[i];
            if (sum_r == (N - i - 1) * d - (allsum_r - sum_r)) {
                ok = sum_r <= K;
                break;
            }
        }
        if (ok) {
            cout << d << endl;
            return 0;
        }
    }
}
