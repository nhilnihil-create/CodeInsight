#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll a,b,k;
    cin >> a >> b >> k;
    if(k >= a+b) cout << 0 << " " << 0 << endl;
    else if(a < k) cout << 0 << " " << b - (k - a) << endl;
    else cout << a -k << " " << b << endl;
    return 0;
}