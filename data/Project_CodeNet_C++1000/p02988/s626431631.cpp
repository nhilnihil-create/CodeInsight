#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int ans = 0;
    for (int i = 1; i < n-1; i++)
    {
        if(p[i-1] < p[i] && p[i] < p[i+1] || p[i-1] > p[i] && p[i] > p[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}