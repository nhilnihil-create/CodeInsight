#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N+1,0), B(M+1,0);
    ll a, b;
    for (ll i=1; i<N+1; i++) {
        cin >> a;
        A[i] = a + A[i-1];
    }
    for (ll i=1; i<M+1; i++) {
        cin >> b;
        B[i] = b + B[i-1];
    }

    // vector<ll> c(N);
    ll maxj = M;
    ll ans = 0;
    for (ll i=0; i<N+1; i++) {
        if (A[i] > K) {
            break;
        }
        for (ll j=maxj; j>=0; j--) {
            if (A[i]+B[j] <= K) {
                ans = max(ans,i+j);
                maxj = j;
                break;
            }
        }
    }
    
    cout << ans << endl;
}