#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), ans(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    for (int i = 0; i < N; i++) ans.at(A.at(i) - 1) = i + 1;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) cout << ans.at(i) << endl;
        else cout << ans.at(i) << " ";
    }
}