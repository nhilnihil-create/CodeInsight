#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int x;
    cin >> x;
    int yen500 = x/500;
    int yen5 = (x - (500*yen500))/5;
    int ans = 1000*yen500+5*yen5;
    cout << ans << endl;
    return 0;  
}