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
    ll S; cin >> S;
    vector<ll>dp(S+1,0);
    for(ll i = 3; i <= S; i++) dp[i] = 1;
    for(ll i = 3; i <= S; i++)
    {
        if(i-3 < 3) continue;
        for(ll j = 3; j <= i-3; j++)
        {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[S] << endl;
}