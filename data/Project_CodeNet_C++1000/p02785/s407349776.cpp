#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (ll i=0; i<N; i++) {
        cin >> H[i];
    }
    sort(H.begin(),H.end());
    reverse(H.begin(),H.end());
    if (N<=K) {
        cout << 0 << endl;
        exit(0);
    }
    for (ll i=0; i<K; i++) {
        H[i] = 0;
    }
    ll ans = 0;
    for (ll i=0; i<N; i++) {
        ans += H[i];
    }
    cout << ans << endl;
}