#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

void solve(){
	int n;
	cin>>n;
	vi vs(n);
	unordered_map<int,ll> mp,inc,ninc;
	for(int &x:vs){
		cin>>x;
		mp[x]++;
	}
	ll s=0;
	for(auto &x:mp){
		inc[x.ff] = (x.ss*(x.ss-1LL))/2LL;
		s+=inc[x.ff];
		if(x.ss > 1LL)
			ninc[x.ff] = ((x.ss-1LL)*(x.ss-2LL))/2LL;
		else
			ninc[x.ff]=0LL;
	}
	for(int i=0;i<n;++i){
		cout << s - inc[vs[i]] + ninc[vs[i]] << endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}