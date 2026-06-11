#include "bits/stdc++.h"
using namespace std;

using int64 = long long;

vector<int64> divisor(int64 n) {
    vector<int64> res;
    for (int64 i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int64 sum = 0;
    for (int i = 0; i < N; ++i) sum += A[i];

    vector<int64> div = divisor(sum);
    sort(div.rbegin(), div.rend());

    for (auto& d: div) {
        vector<int64> m(N);
        int64 sum = 0;
        for(int i = 0; i < N; ++i) {
            m[i] = A[i] % d;
            sum += m[i];
        }
        sort(m.rbegin(), m.rend());
        int64 t = sum;
        for (int i = 0; i < t / d; ++i) sum -= m[i];

        if (sum <= K) {
            cout << d << endl;
            return 0;
        }



    }
}