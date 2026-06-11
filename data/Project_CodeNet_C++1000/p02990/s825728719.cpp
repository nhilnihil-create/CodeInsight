#include <iostream>
#include <cstring>
#include<complex>
#include <algorithm>
#include<iomanip>
#include<map>
#include<vector>
using namespace std;
#define point complex<double> 
double dot(point a, point b)
{
	return (conj(a) * b).real();
}
double cross(point a, point b)
{
	return (conj(a) * b).imag();
}
#define mod 1000000007
    typedef long long ll;
        ll dp[2005][2005];
    int main()
    {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n, k;
        cin >> n >> k;
        dp[0][0] = 1; dp[1][1] = 1; dp[1][0] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = 1; dp[i][i] = 1;
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i - 1][j]%mod + dp[i - 1][j - 1]%mod;
            }
        }
        int r = n - k;
        for (int i = 1; i <= k; i++)
        {
            cout << ((dp[k - 1][i - 1] % mod) * (dp[r + 1][i] % mod))%mod << '\n'; 
        }
        return 0;
    }
