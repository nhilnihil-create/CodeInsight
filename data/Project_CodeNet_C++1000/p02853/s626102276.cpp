#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if(a == 1) ans+= 300000;
    if(a == 2) ans+= 200000;
    if(a == 3) ans+= 100000;
    if(b == 1) ans+= 300000;
    if(b == 2) ans+= 200000;
    if(b == 3) ans+= 100000;
    if(a == 1 && b == 1) cout << ans+400000 << endl;
    else cout << ans << endl;
    return 0;
}