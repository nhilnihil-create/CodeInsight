// Sakhiya07 - Yagnik Sakhiya

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>

#define mp make_pair
#define bp __builtin_popcountll
#define MOD  1000000007
const int N = 200005;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
string s;
ll dp[N][2];
ll solve1(ll id,ll free)
{
    if(id==s.size())   return 1;
    ll ans = dp[id][free];
    if(ans!=-1)   return ans;
    ans = 0;
    if(free==0)
    {
        ans = (ans + 3*solve1(id+1,0))%MOD;
    }
    else
    {
        ll range = s[id] - '0';
        if(range==0)   
        {
            ans = solve1(id+1,free);
        }
        else
        {
            ans = (ans + solve1(id+1,0))%MOD;
            ans = (ans + 2*solve1(id+1,1))%MOD;
        }    
    }
    return dp[id][free] = ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin >> s;
    ll ans = solve1(0,1);
    cout<<ans;
}

int main()
{
    FAST;
    ll t = 1;
  //  cin >> t;
    while(t--)
    {
        solve();
    }
}