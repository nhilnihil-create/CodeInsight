#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forr(i,n) for(int i = 0;i < (int)n; i++)
#define forn(i,n) for(int i = (int)(n-1); ~i ;i--)
#define deb(x) cout<<#x<<" " <<x<<"\n";
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define pb push_back
#define mpa make_pair
#define endl "\n"
#define ar array



void solve(){
	int n;
	cin >> n;
	int ans = 1e18;
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans = min(ans,(n/i)+i-2);
		}
	}
	cout << ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		solve();	
	}
	return 0;
}
