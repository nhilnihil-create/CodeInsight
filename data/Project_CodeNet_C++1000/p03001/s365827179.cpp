#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    long double w, h, x, y;
    cin >> w >> h >> x >> y;
    long double res = w*h/2;
    cout << fixed << setprecision(10) << res << " ";
    if(2*x==w && 2*y==h){cout << 1 << endl;}
    else{cout << 0 << endl;}
    return 0;
}