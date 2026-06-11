#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int mod = 1e9+7;
const ll maxn = 2e5+10;

ll fat[maxn],inv[maxn];

ll modpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b/=2;
	}
	return res;
}

void precalc(){
	fat[0] = 1;
	for(int i=1;i<maxn;++i){
		fat[i] = (i*fat[i-1])%mod;
	}
	inv[0] = 1;
	for(int i=1;i<maxn;++i){
		inv[i] = modpow(fat[i],mod-2)%mod;
	}
}

ll C(ll n,ll k){
	ll res=1;
	for(ll i=n;i>=n-k+1;--i){
		res = (res*i)%mod;
		if(res<0)
			res+=mod;
	}
	res = (res*inv[k])%mod;
	if(res<0)
		res+=mod;
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	precalc();
	int n,a,b;
	cin>>n>>a>>b;
	ll tot = (modpow(2,n)-1)%mod;
	ll xa=C(n,a),xb=C(n,b);
	tot=(tot-xa-xb)%mod;
	if(tot<0)
		tot+=mod;
	cout<<tot<<endl;
	return 0;
}