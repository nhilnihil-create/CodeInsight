//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N, R; cin >> N >> R;
    int ans;
    if (N >= 10) ans = R;
    else ans = R + 100 * (10 - N);

    cout << ans << endl;
}


int main() {
    solve();
    return 0;
}