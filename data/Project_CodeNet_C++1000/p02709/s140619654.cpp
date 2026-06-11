#include<bits/stdc++.h>	
 
#define f first
#define s second
#define pb push_back
 
#define ll long long
 
#define int ll
 
#define mp make_pair
  
using namespace std;
                       
 
const int inf = 1e9 + 7;
 
const ll ll_inf = 1e18 + 7;
const int K = 2e5;
const int N = 2e5 + 300;
                                         
ll binpow (ll a, ll n)
{
	if(n == 0)
		return 1ll;
    ll res = 1;
    while (n) {
        if (n & 1)
        {
            res *= a;
            res %= inf;
        }      	
        a *= a;
        n >>= 1;
        a %= inf;
    }                          
    return res;
}   
          
  
 
void boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}  
 
int n,dp[2010][2010]; 
 
pair<int, int> a[2020];
 
int rec(int l, int r, int v) 
{
	if(l == r) 
		return 0;              
 
	if(dp[l][r] != -1) 
		return dp[l][r];
	dp[l][r] = max(rec(l + 1, r, v - 1) + abs(l - a[v].s) * a[v].f, rec(l, r - 1, v - 1) + abs(r - 1 - a[v].s) * a[v].f);
	return dp[l][r];
}
 
main() 
{
	cin >> n;
	for (int i = 0;i <= n + 1;i++)
	{
		for (int j = 0;j <= n + 1;++j)
			dp[i][j] = -1;
	}
	for(int i = 1;i <= n;++i) 
	{
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a + 1, a + n + 1);         
	cout << rec(1, n + 1, n);
}