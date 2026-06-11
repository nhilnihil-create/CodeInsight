#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i%3 != 0 && i%5 != 0){
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}