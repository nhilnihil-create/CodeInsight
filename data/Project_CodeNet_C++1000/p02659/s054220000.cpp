#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll a;
    double b;
    cin >> a >> b;
    ll ans = (a * (ll)(b * 100 + 0.00001)) / 100;
    cout << ans << endl;

    return 0;
} 