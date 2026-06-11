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
const int N = 2e3 + 300;
                                         
ll binpow (ll a, ll n)
{
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

int ans;

int n,a[N],dp[N][N];

vector<pair<int,int> >v;

main()
{
	cin >> n;
	for (int i = 0;i < n;++i)
	{
		cin >> a[i];
		v.pb(mp(a[i],i));
	}               
 	sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
 	for (int i = 0;i < n;++i) 
 	{
        for(int l = 0;l <= i;++l) 
        {
        	int r = i - l;
            dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + v[i].f * abs(v[i].s - l));
            dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + v[i].f * abs(n - 1 - r - v[i].s));
        }
    }
                
                   
   	for (int i = 0;i <= n;++i)
        ans = max(ans, dp[i][n - i]);
 
    cout << ans << endl;
}