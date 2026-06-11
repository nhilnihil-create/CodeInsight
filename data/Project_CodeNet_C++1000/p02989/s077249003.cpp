#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> d(N);
    for (int64_t i = 0; i < N; i++) {
        cin >> d.at(i);
    }

    sort(d.begin(), d.end());
    int64_t ans = d.at(N / 2) - d.at(N / 2 - 1);
    cout << ans << endl;
}