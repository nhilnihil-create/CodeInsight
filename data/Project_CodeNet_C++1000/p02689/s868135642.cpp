#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), A(M), B(M);
    vector<ll> vec(N,0);
    for (ll i=0; i<N; i++) cin >> H[i];
    for (ll i=0; i<M; i++) {
        cin >> A[i] >> B[i];
        if (H[A[i]-1] <= H[B[i]-1]) vec[A[i]-1]++;
        if (H[A[i]-1] >= H[B[i]-1]) vec[B[i]-1]++;
    }

    ll ans = 0;
    for (ll i=0; i<N; i++) {
        if (vec[i]==0) ans++;
    }

    cout << ans << endl;
}