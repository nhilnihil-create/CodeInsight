#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll a,b;
    cin >> a >> b;
    ll ans = a+b;
    if(ans%2 == 1) cout << "IMPOSSIBLE" << endl;
    else cout << ans/2 << endl;
    return 0;
}