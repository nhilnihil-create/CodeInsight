#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=500+5;
const int N=3000+5;
const ll oo=1e18+5;
const ll mod=998244353;

ll mul(ll a,ll b){
	return a*b%mod;
}

ll poww(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1) r=mul(r,a);
		a=mul(a,a);
		b>>=1;
	}
	return r;
}

void add_self(ll& a,ll b){
	a+=b;
	if(a>=mod) a-=mod;
}

int n,s;
ll dp[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	ll inv2=poww(2,mod-2);
	dp[0]=poww(2,n);
	for(int i=0;i<n;++i){
		for(int sum=s;sum>=a[i];--sum){
			add_self(dp[sum],mul(dp[sum-a[i]],inv2));
		}
	}
	cout<<dp[s];
	return 0;
}
