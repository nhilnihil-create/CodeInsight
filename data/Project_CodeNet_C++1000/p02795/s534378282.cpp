#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    int ans;
    if(n/h <= n/w){
        ans = n/h;
        if(n%h != 0) ans++;
    }else{
        ans = n/w;
        if(n%w != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}