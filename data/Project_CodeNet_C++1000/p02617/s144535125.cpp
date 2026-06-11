#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	ll n;
	cin>>n;
	ll ans=((n*n)*(n+1))/2;
	ans-=((n-1)*n*(n+1))/3;
	int u,v;
	fr(i,0,n-1){
		cin>>u>>v;
		if(u>v)
			swap(u,v);
		ans-=(u*(n-v+1));
	}
	cout<<ans<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}