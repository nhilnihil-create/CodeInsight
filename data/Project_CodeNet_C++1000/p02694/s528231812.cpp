#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    ll x;
    cin >> x;
    ll yokin = 100;
    ll ans = 0;
    while(yokin < x){
        ll rs  = yokin/100;
        yokin += rs;
        ans++;
    }
    cout << ans << endl;
}