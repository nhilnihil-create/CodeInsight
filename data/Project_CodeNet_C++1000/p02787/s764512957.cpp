/**
 *    author:  Mohamad Milhem
**/

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define MOD ll(1000000007)
#define debug(x) cout << '[' << #x << " is: " << x << "] " <<endl;
#define decimalpoint cout << std::fixed << setprecision(5)
int h,n;
int yes[1003], no[1003];
int dp[10005];



long long calc(int now){
	if (now <= 0)return 0;

	if (dp[now] != -1)return dp[now];


	long long ans = 2e9;

	for (int i = 0 ; i < n ; i++){
		ans = min(ans, calc(now - yes[i]) + no[i]);
	}

	return dp[now] = ans;
}








void solve(){

	cin >> h >> n;

	for (int i = 0 ; i < n ; i++){
		cin >> yes[i] >> no[i];
	}

	memset(dp, -1 , sizeof dp);


	cout << calc(h) << endl;


}



int main()
{
    FAST;
    int t;
    t = 1;

    while(t--){
        solve();
    }
    return 0;
}
