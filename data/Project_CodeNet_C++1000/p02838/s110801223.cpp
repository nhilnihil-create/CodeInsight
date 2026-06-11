#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())
#define endl '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int mod = 1e9+7;

ll poww(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b/=2;
	}
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	int ans=0;
	for(ll i=0;i<60;++i){
		int cnt=0;
		for(int j=0;j<n;++j){
			if((v[j]&(1LL<<i))!=0)
				cnt++;
		}
		ll bit_0 = n-cnt;
		ll tot_bit_1_at_i = (cnt*bit_0)%mod;
		ll dec_val = ((poww(2LL,i)%mod)*tot_bit_1_at_i)%mod;
		ans = (ans+dec_val)%mod;
	}
	cout<<ans<<endl;
	return 0;
}