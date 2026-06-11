#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll h,n;
    cin >> h >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll total = 0;
    rep(i,n) total += a[i];
    if(h <= total){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}