/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

void solve(){
	int i,j;
	int n;cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ll ans=0;
	int mx=a[0];

	for (int i = 1; i < n; ++i)
	{
		ans+=max(0,mx-a[i]);
		mx=max(mx,a[i]);
	}

	printf("%lld\n",ans);
}


int main(){
	// ios_base::sync_with_stdio(false);
 //    cin.tie(0);
    
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
