#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int64_t> B(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> B.at(i);

    int64_t res = B.at(0) + B.back();
    for (int i = 0; i + 1 < B.size(); i++) {
        res += min(B.at(i), B.at(i + 1));
    }
    cout << res << endl;
}