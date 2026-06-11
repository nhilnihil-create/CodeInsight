#include <bits/stdc++.h>          
using namespace std;     
typedef long long ll;          

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> H(N);
    for (ll i=0; i<N; i++) {
        cin >> H[i];
    }
    vector<ll> A(M);
    vector<ll> B(M);
    for (ll i=0; i<M; i++) {
        cin >> A[i] >> B[i];
    }

    //
    vector<ll> good(N,1);
    for (ll i=0; i<M; i++) {
        if (H[A[i]-1] > H[B[i]-1]) {
            good[B[i]-1] = 0;
        }
        else if (H[A[i]-1] == H[B[i]-1]) {
            good[A[i]-1] = 0;
            good[B[i]-1] = 0;
        }
        else {
            good[A[i]-1] = 0;
        }
    }
    ll ans = 0;
    for (ll i=0; i<N; i++) {
        ans += good[i];
    }
    cout << ans << endl;
}