#include <bits/stdc++.h>
using namespace std;
# define ll  long long int
# define ld  long double
# define pb push_back
# define pp pop_back
# define ff first
# define ss second
# define mp make_pair
# define ac accumulate
# define mod 1000000007
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int p[5005];
int c[5005];
vector<ll> prefixSums;
bool vis[5005];

void dfs(int src, ll currSum){
	if(vis[src])
		return;
	vis[src] = true;
	currSum += c[src];
	prefixSums.push_back(currSum);
	dfs(p[src], currSum);
}

int  main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif
     IOS
     int n, k;
     cin >> n >> k;
     for(int i = 0; i < n; i++){
     	cin >> p[i];
     	p[i]--;
     }
     for(int i = 0; i < n; i++)
     	cin >> c[i];
     ll ans = -1e18;
     for(int i = 0; i < n; i++){
     	memset(vis, false, sizeof(vis));
     	dfs(i, 0);
     	if(prefixSums.back() > 0 && k > (int)prefixSums.size()){
     		ll cycles = (ll)(k/(int)prefixSums.size());
     		ll left = (ll)(k%(int)prefixSums.size());
     		ll maxi = -1e18;
     		for(int x = 0; x < (int)prefixSums.size(); x++)
     			maxi = max(maxi, prefixSums[x]);
     		ans = max(ans, (cycles - 1LL)*(prefixSums.back()) + maxi);
     		maxi = -1e18;
     		for(int x = 0; x < left; x++)
     			maxi = max(maxi, prefixSums[x]);
     		ans = max(ans, (cycles*prefixSums.back()) + maxi);
     	}
     	else{
     		for(int j = 0; j < min((int)prefixSums.size(), k); j++)
     			ans = max(ans, prefixSums[j]);
     	}
     	prefixSums.clear();
     }
     cout << ans;
     return 0;
}