#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    string ans = "Yes";
    int N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];
    rep(i, N - 1) {
        if(H[N - 2 - i] - 1 > H[N - 1 - i]) {
            ans = "No";
            break;

        } else if(H[N - 2 - i] - 1 == H[N - 1 - i])
            H[N - 2 - i]--;
    }

    cout << ans << endl;
}