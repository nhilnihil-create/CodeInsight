#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if(k <= a) cout << k << endl;
    else if(k <= a + b) cout << a << endl;
    else cout << a - (k - a - b) << endl;
}