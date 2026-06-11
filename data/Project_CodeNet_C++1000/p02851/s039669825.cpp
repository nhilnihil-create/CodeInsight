#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> vs(n+1, 0);
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		cin >> vs[i]; vs[i]%=k;
		if(vs[i]==0) vs[i] = 1;
		else vs[i] = -(vs[i]-1);
	}
	for(int i=1; i<=n; ++i){
		vs[i] += vs[i-1];
		if(vs[i]>0) vs[i]%=k;
		else vs[i] = (((-vs[i])%k)*(k-1))%k;
	}
//	for(int i=0; i<=n; ++i)
//		cout << vs[i] << (i==n?'\n':' '); 	
	map<ll, ll> mp;
	for(int i=0; i<=n; ++i){ 
		if(i-k>=0) --mp[vs[i-k]];
		ans += mp[vs[i]];
		++mp[vs[i]];
	}
	cout << ans << endl;

}
