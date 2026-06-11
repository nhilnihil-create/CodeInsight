#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    ll ans = 0;
    for (ll i=0; i<N/2; i++) {
        ans += 2*A[i];
    }
    ans -= A[0];

    if (N%2!=0) {
        ans += A[(N+1)/2-1];
    }

    cout << ans << endl;
}