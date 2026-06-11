#include <bits/stdc++.h>
#define INF 1e7
#define mod 1000000007

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;


int main()
{
    ll N; cin >> N;
    vector<vector<ll>>dp(N+1,vector<ll>(1<<2,0));
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int bit = 0; bit < (1<<2); bit++)
        {
            if(bit == 0)
            {
                dp[i][bit] = dp[i-1][bit]*8;
                dp[i][bit] %= mod;
            }
            else if(bit == 1<<0)
            {
                dp[i][bit] = dp[i-1][0] + dp[i-1][bit]*9;
                dp[i][bit] %= mod;
            }
            else if(bit == 1<<1)
            {
                dp[i][bit] = dp[i-1][0] + dp[i-1][bit]*9;
                dp[i][bit] %= mod;
            }
            else
            {
                dp[i][bit] = dp[i-1][1<<1] + dp[i-1][1<<0] + dp[i-1][bit]*10;
                dp[i][bit] %= mod;
            }
        }
    }
    cout << dp[N][(1<<0)+(1<<1)] << endl;
}