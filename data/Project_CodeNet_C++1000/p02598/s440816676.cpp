# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+5;

ll n,k;
ll a[N];

bool check(ll x){
	ll ans=0;
	for(int i=0;i<n;++i){
		if(a[i]==x)continue;
		ans+=a[i]/x;
	}	
	return ans<=k;
}

void solve(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}	
	ll l=1,r=1e9,ans=1e9;
	while(l<=r){
		ll m=(l+r)/2;
		if(check(m)){
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout<<ans;
}

int main(){
	ios_base :: sync_with_stdio(false);
	int test = 1; 
	//cin >> test;	
	while (test--){
		solve();
	}
	return 0;
}