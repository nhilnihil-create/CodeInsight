#include <bits/stdc++.h>
typedef long long ll;

#define pll pair<ll,ll>
#define ff first
#define snd second
#define pb push_back
#define vll vector<ll>
#define vpll vector<pll>
#define endl "\n"
#define MOD 1000000007
using namespace std;

ll const N = 1e5+1;

ll exponentMod(ll A, ll B)  
{  
    // Base cases  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
  
    // If B is even  
    ll y;  
    if (B % 2 == 0) {  
        y = exponentMod(A, B / 2);  
        y = (y * y) % MOD;  
    }  
  
    // If B is odd  
    else {  
        y = A % MOD;  
        y = (y * exponentMod(A, B - 1) % MOD) % MOD;  
    }  
  
    return ((y + MOD) % MOD);  
}

void solve()
{
   ll n,k;
   cin>>n>>k;
   ll dp[k+1];
   ll count = 0;
   memset(dp,0,sizeof(dp));
   ll ans = 0;
   for(ll i=k;i>=2;i--)
   {
        ll p = (k/i);
        dp[i] = (dp[i] + exponentMod(p,n))%MOD;
        ll j = i + i;
        while(j<=k)
        {
                dp[i] = (dp[i] - dp[j] + MOD)%MOD;
                j = j+i;
        }
        count = (count + dp[i])%MOD;
        ll temp = (dp[i]* i)%MOD;
        ans = (ans + temp)%MOD;
   }
   
   ll p = exponentMod(k,n)%MOD;
   p = (p - count + MOD)%MOD;
   ans = (ans + p)%MOD;
   
   cout<<ans;
}
 
int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    int t=1;
	    //cin>>t;
	    while(t--)
	    {
	            solve();
	    }
	    return 0;
}