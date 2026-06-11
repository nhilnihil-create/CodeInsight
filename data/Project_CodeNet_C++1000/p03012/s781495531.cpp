#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    int l = 0, r = 0;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        r += W[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        l += W[i];
        r -= W[i];
        ans = min(ans, abs(r - l));
    }
    cout << ans << endl;
    return 0;
}
