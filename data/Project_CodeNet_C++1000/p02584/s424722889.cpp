#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    ll N = X/D; // count
    ll d = X%D; // distance
    ll ans;
    if (N >= K) {
        ans = X-K*D;
    }
    else if (K%2 == 0) {
        if (N%2 == 0) {
            ans = d;
        }
        else {
            ans = D-d;
        }
    }
    else {
        if (N%2 != 0) {
            ans = d;
        }
        else {
            ans = D-d;
        }
    }
    cout << ans << endl;
}