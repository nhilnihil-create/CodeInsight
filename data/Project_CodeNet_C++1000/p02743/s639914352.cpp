#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll a, b, c; cin >> a >> b >> c;
    ll d = (c - a - b);
    if(d > 0 && (4*a*b) < (d*d)) cout << "Yes";
    else cout << "No";
    cout << endl;
    return 0;
}