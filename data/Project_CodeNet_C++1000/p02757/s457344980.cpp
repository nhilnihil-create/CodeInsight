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

using namespace std;

const int maxn = 10000;
//const int mod = 1e9+7;

int n,mod;
string s;

void solve(){
	cin>>n>>mod>>s;
	if(__gcd(10,mod)==1){
		map<ll,ll> mp; mp[0] = 1;
		ll pot=1,pre=0,ans=0;
		for(int i=n-1;i>=0;--i){
			pre+=(s[i]-'0')*pot;
			pre%=mod;
			ans+=mp[pre];
			mp[pre]++;
			pot*=10LL;
			pot%=mod;
			if(pot==0)
				pot=1;
		}
		cout<<ans<<endl;
	}
	else{
		ll ans=0;
		for(int i=0;i<n;++i){
			if((s[i]-'0')%mod==0)
				ans+=i+1;
		}
		cout<<ans<<endl;
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