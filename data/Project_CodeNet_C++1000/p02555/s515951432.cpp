
#include<iostream>

using namespace std;

#define ios         ios_base::sync_with_stdio(false);
#define ll          long long
#define ld          long double
#define db(x)       cout << "[" << #x << ": " << (x) << "]\n"
#define db2(x,y)    cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]\n"
#define db3(x,y,z)  cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]  [" << #z << ": " << (z) << "]\n"
#define cn          107
#define sn          2007
#define bn          1000007
#define M           1000000007
#define inf         LLONG_MAX


ll dp[sn];

ll dpf(ll n)
{
        if(n < 3) return 0;
        if(dp[n]) return dp[n];
        dp[n] = 1;
        for(ll i = 3; i+3 <= n; i++)
        {
                dp[n] += dpf(n-i);
                dp[n] %= M;
        }
        return dp[n];
}

int main()
{
        ios;
        dp[0] = dp[1] = dp[2] = 0; dp[3] = 1;
        ll n; cin >> n;
        cout << dpf(n); cout << "\n";
	return 0;
}

