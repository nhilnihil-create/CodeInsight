//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, K; cin >> N >> K;
    int ans = 0;

    while (N > 0) {
        N /= K;
        ans++;
    }

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}