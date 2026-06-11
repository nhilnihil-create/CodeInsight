#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);

    long long ans;
    if(X/D > K){
        ans = X - K*D;
    } else {
        ll times = X/D;
        K -= times;
        X -= times*D;
        if(K%2 == 1) ans = abs(X - D);
        else ans = X;
    }
    cout << ans << '\n';
    return 0;
}
//Saw a part of the editorial