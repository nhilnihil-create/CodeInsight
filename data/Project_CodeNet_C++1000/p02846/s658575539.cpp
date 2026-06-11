#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t[2], a[2], b[2];
    cin >> t[0] >> t[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];

    ll p = (b[0]-a[0])*t[0];
    ll q = (b[1]-a[1])*t[1];
    if(p + q == 0){
        cout << "infinity\n";
    } else if (abs(q) < abs(p) || (q > 0 && p > 0) || (q < 0 && p < 0)){
        cout << 0 << endl;
    } else {
        ll dx = abs(p + q);
        ll n = abs(p) / dx;
        if(abs(p) == n * dx){
            cout << 2 * n << endl;
        } else {
            cout << 2 * n + 1 << endl;
        }
    }
    return 0;
}