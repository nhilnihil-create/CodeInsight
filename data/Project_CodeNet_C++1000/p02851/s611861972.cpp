// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int const mxn=2e5+5;

int a[mxn];
ll dp[mxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	a[0]=0; dp[0]=0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		dp[i] = dp[i-1]+a[i];
	}
	for(int i=0; i<=n; i++){
		dp[i]-=i;
		dp[i] %= k;
		while(dp[i]<0)dp[i]+=k;
	}
	ll ans=0;
	int ptr=0;
	map<ll,int>mp;
	while(ptr<=n){
		if(ptr-k>=0)mp[dp[ptr-k]]--;
		ans += mp[dp[ptr]];
		mp[dp[ptr]]++;
		ptr++;
	}
	cout << ans << endl;
}	
