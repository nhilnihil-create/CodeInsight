#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    ll l = 0, ans = 1;
    string S;
    cin >> N >> S;
    rep(i, N * 2) {
        if ((S[i] == 'B') ^ (i % 2)) {
            l++;
        } else {
            if (l < 1) {
                cout << 0 << endl;
                return 0;
            }
            ans = (ans * l) % MOD;
            //cout << i << " " << ans << endl;
            l--;
        }
    }
    if (l != 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, N) {
        ans = (ans * (i + 1)) % MOD;
    }
    cout << ans << endl;
}