#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {

    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    string ans = "";
    rep(i, N) {
        ans += S[i];
        ans += T[i];
    }

    cout << ans << endl;

    return 0;
}
