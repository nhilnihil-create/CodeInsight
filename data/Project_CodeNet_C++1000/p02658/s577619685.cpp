#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll ans = 1;
    for (ll i=0; i<N; i++) {
        cin >> A[i];
        if (A[i]==0) {
            ans = 0;
        }
    }

    if (ans==0) {
        cout << 0 << endl;
        exit(0);
    }
    
    ll judge = pow(10,18);
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    
    for (ll i=0; i<N; i++) {
        if (ans <= judge/A[i]) {
            ans *= A[i];
        }
        else {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}