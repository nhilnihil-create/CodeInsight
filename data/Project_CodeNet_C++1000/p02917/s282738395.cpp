#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> values(N-1);
    for (int &x : values) cin >> x;
    if (N == 2) {
        cout << 2 * values.front() << '\n';
        exit(0);
    }
    int res = values.front();
    for (int i = 0; i+1 < N-1; ++i) {
        res += min(values[i], values[i+1]);
    }
    cout << res + values.back() << '\n';
}
