#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for(size_t i = 0; i < N; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    auto it = lower_bound(h.begin(), h.end(), K);
    ans = h.end() - it;

    cout << ans << endl;
}