#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> C(N + 1, 0);
    for(int i=0; i<N; ++i) {
        int a; cin >> a;
        C[a] += 1;
    }
    vector<long long> D(N + 1, 0);
    for(int i=0; i<=N; ++i) {
        D[C[i]] += 1;
    }
    vector<long long> sum1(N + 1, 0), sum2(N + 1, 0);
    for(int i=1; i<=N; ++i) {
        sum1[i] = sum1[i - 1] + D[i];
        sum2[i] = sum2[i - 1] + i * D[i];
    }

    vector<long long> F(N + 1, 0);
    for(int x=1; x<=N; ++x) {
        F[x] = (sum2[x] + x * (sum1[N] - sum1[x])) / x;
    }

    for(int k=1; k<=N; ++k) {
        auto it = lower_bound(rbegin(F), rbegin(F) + N, k);
        if(it == rbegin(F) + N) cout << 0 << endl;
        else cout << N - (it - rbegin(F)) << endl;
    }
}