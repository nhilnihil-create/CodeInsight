#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;
    if(v<=w) {
        cout << "NO" << endl;
        return 0;
    }
    if(a > b) {
        if(b-t*w >= a-t*v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }else {
        if(b+t*w <= a+t*v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}