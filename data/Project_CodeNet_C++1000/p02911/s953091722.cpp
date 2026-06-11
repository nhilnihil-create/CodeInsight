#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, Q;  cin >> N >> K >> Q;
    long long minus = 0;
    vector<long long> plus(N);
    for (int i = 0; i < Q; ++i) {
        int a;  cin >> a;
        ++minus;
        ++plus[a - 1];
    }
    for (int i = 0; i < N; ++i) {
        if (K - minus + plus[i] <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
