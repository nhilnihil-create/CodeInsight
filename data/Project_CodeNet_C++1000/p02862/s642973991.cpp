#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int X, Y;
int mod = 1000000007;
int F[1000010], R[1000010];

int con(int n, int m)
{
    if(n < m)return 0;
    if(m < 0)return 0;
    return F[n] * R[m] % mod * R[n - m] % mod;
}

int pow_mod(int a, int b)
{
    if(b == 0)return 1;
    int ret = pow_mod(a * a % mod, b / 2);
    if(b & 1LL)ret = ret * a % mod;
    return ret;
}

signed main()
{
    cin >> X >> Y;

    if((X + Y) % 3)
    {
        cout << 0 << endl;
        return 0;
    }

    F[0] = 1;
    for(int i = 1; i < 1000010; i++)F[i] = F[i - 1] * i % mod;
    rep(i, 1000010)R[i] = pow_mod(F[i], mod - 2);

    int N = (X + Y) / 3;
    int d = (2 * Y - X) / 3;

    cout << con(N, d) << endl;

    return 0;
}
