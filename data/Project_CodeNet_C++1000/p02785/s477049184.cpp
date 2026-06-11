#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    rep(i,N) cin >> H.at(i);
    ll ans = 0;
    sort(H.begin(), H.end(), greater<ll>());
    if (N > K) {
        for (int i = K; i < N; ++i) {
            ans += H.at(i);
        } 
    }
    cout << ans << endl;
}
