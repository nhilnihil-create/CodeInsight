#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (size_t i = 0; i <= n; i++) if(GetDigit(i)%2 == 1) ans++;
    cout << ans << endl;
    return 0;
}
