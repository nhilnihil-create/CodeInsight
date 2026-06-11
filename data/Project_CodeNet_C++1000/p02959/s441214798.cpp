#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N + 1), B(N);
    rep(i,N+1) cin >> A.at(i);
    rep(i,N) cin >> B.at(i);
    ll ans = 0;

    rep(i,N+1) {
        if (i == 0) {
            ll beat = min(A.at(0), B.at(0));
            ans += beat;
            B.at(i) -= beat;
        } else if (i == N) {
            ll beat = min(A.at(N), B.at(N - 1));
            ans += beat;
        } else {
            ll beatlow = min(A.at(i), B.at(i - 1));
            ll beathigh = min(A.at(i) - beatlow, B.at(i));
            ans += beatlow + beathigh;
            B.at(i) -= beathigh;
        }
    }
    cout << ans << endl;
}
