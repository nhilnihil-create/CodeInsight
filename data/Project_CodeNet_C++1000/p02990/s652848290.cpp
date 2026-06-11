#include <bits/stdc++.h>
#define int long long
#define vi vector <int>
#define si set <int>
#define mii map <int,int>
#define pii pair <int,int>
#define endl "\n"
#define FOR(P,Q) for(int P=0;P<(Q);P++)
#define FORR(P,Q) for(int P=1;P<=(Q);P++)
#define rep(P,R,Q) for(int P=(R);P<=(Q);P++)
#define repb(P,R,Q) for(int P=(R);P>=(Q);P--)
#define pb push_back
#define eb emplace_back
#define bug(j) cerr<<j<<" "
#define NL cerr<<endl
#define D1(arr,a) rep(i,1,a) bug(arr[i]) 
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;

const int mod = 1e9+7;
    
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr);
	#endif
	int tces=1;
	// cin>>tces;
	while(tces--){
		// int n;
		// cin>>n;
		// vi v(n+5);
		// FORR(i,n){
		// 	cin>>v[i];
		// }
		int n,k;
		cin>>n>>k;
		int ncr[2005][2005];
		memset(ncr,0, sizeof(ncr));
		ncr[0][0]=1;
		FOR(i,n+1){
			ncr[i][0]=1;
		}
		FORR(i,n+1){
			FORR(j,n){
				ncr[i][j]=(ncr[i-1][j-1]%mod+ncr[i-1][j]%mod)%mod;
			}
		}
		FORR(i,k){
			int ans=(ncr[k-1][i-1]%mod * ncr[n+1-k][i]%mod)%mod;
			cout<<ans<<endl;
		}
		// unordered_map<int,int> m;
		// FORR(i,n-1){
		// 	m[v[i+1]-v[i]]++;
		// }

	}
	
return 0;
}