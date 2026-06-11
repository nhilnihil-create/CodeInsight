#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    int t = 0;
    int s1 = 0, s2 = 0;
    int ans = 1000000;
    for ( int j = 0; j < n; j++)
    {
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < t; i++)
        {
            s1 += w[i];
        }
        for (int i = t; i < n; i++)
        {
            s2 += w[i];
        }
        if(ans > abs(s2-s1)) ans = abs(s1-s2);
        t++;

    }
    cout << ans << endl;
    
    return 0;
}