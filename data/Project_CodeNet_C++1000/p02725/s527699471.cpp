#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define rep(p,a,b)    for(ll p=a;p<b;p++)
#define sz(v) ((int)v.size())
#define all(v) (v).begin(), (v).end()
#define INF 0x3f3f3f3f

typedef pair<int,pair<int,int>> ppi;

ll nextPowerOf2(ll n)   
{ 
	n--; 
	n |= n >> 1ll; 
	n |= n >> 2ll; 
	n |= n >> 4ll; 
	n |= n >> 8ll; 
	n |= n >> 16ll; 
	n++; 
	return n; 
}


int main() {
	
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t,i,j,n,ans,k;
	
	//cin>>t;
	//cout<<t;
	t = 1;
	while(t--)
	{
		cin>>k>>n;
		ans = LLONG_MAX;
		
		vector<ll> v(n);
		rep(p,0,n)cin>>v[p];

		rep(p,0,n-1)ans = min(ans,k-abs(v[(p+1)%n] - v[p]));
		ans = min(ans,k-(k-v[n-1]+v[0]));
		cout<<ans;
	}
	return 0;
}