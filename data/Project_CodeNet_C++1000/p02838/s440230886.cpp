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

const int maxn = 3e5+10;
const int mod = 1e9+7;

ll v[maxn];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	for(int i=0;i<60;++i){
		ll cnt=0;
		for(int j=0;j<n;++j){
			if((v[j]&(1LL<<i)))
				cnt++;
		}
		ll one_bit = (cnt*(n-cnt))%mod;
		ll to_dec = (((1LL<<i)%mod)*one_bit)%mod;
		ans = (ans+to_dec)%mod;
	}
	cout<<ans<<endl;
	return 0;
}