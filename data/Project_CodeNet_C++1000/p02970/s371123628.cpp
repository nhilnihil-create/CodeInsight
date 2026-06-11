#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,d;
    cin >> n >> d;
    int k = 2*d+1;
    int ans = 0;
    while(n > 0){
        n -= k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}