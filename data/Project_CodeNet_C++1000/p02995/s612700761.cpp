#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll l = lcm(c, d);
    ll A = a - 1 - (a - 1) / c - (a - 1) / d + (a - 1) / l;
    ll B = b - b / c - b / d + b / l;
    cout << B - A << endl;
    return 0;
}