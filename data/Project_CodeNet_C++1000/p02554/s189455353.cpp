#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define f first
#define s second
#define matrix vector<vector<char>>
#define zero(n,m) matrix(n , vector<char>(m,'0'))
#define one(n,m) matrix(n , vector<ll>(m,1))
#define pii pair<int,int>
#define point complex<ld>
#define angle(a) (atan2((a).imag() , (a).real() ))
#define pi acos(-1)
#define X real()
#define Y imag()
const int N = 1e6+5;

ll n , dp[N][2][2] , mod=1e9+7;

ll solve(int i , bool zero , bool nine)
{
    if (i>n)
        return (zero && nine);

    if (dp[i][zero][nine] != -1)
        return dp[i][zero][nine];

    ll ans=solve(i+1 , 1 , nine);
    ans = (ans+solve(i+1 , zero , 1))%mod;
    ans = (ans+1ll*8*solve(i+1,zero,nine))%mod;
  
    return dp[i][zero][nine] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    memset(dp , -1 , sizeof(dp));

    cout << solve(1,0,0) << '\n';
  
    return 0;
}