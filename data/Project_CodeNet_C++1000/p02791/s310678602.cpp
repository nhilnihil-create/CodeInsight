#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int min_P, ans;
    min_P  = INT_MAX;
    ans = 0;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        min_P = min(min_P, P);
        if(min_P == P) ans++;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}