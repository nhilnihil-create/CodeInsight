/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 110
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================
int32_t  main()
{
    io;
    string s;
    cin>>s;
    int n = s.size();
    ll ans = 0;
    ll dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i<= n; i++)
    {
        int k= s[i-1] - '0';
        dp[i][0] = min(dp[i-1][0]+k, dp[i-1][1] + 10-k);
        dp[i][1] = min(dp[i-1][0] + k + 1, dp[i-1][1] + 10 - k - 1);
    }
    cout<<dp[n][0];
    return 0;
}