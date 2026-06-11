#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<ll> h(N);
    rep(i, 0, N) { cin >> h[i]; }
    bool flg = true;

    for(int i = N - 2; i >= 0; i--) {
        if(h[i] > h[i + 1]) {
            h[i]--;
        }
    }
    // rep(i, 0, N) { cout << h[i] << " "; }
    // cout << endl;
    rep(i, 0, N - 1) {
        if(h[i] > h[i + 1]) {
            flg = false;
        }
    }
    cout << (flg ? "Yes" : "No") << endl;
    return 0;
}
