#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K, Q; cin >> N >> K >> Q;
    vector<int64_t> A(N, K);
    for (int i = 0; i < Q; i++) {
        int64_t x; cin >> x;
        A.at(x - 1)++;
    }

    for (int i = 0; i < N; i++) {
        if (1 <= A.at(i) - Q) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}