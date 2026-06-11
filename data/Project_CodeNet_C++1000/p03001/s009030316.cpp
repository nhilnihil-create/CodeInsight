#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    double m=w;
    m *= h;
    m/=2;

    cout << fixed << setprecision(10);
    cout << m << ' ';

    if(2*x==w && 2*y==h) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}