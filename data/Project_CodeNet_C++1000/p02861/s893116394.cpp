#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<int,int>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}


int main() {
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++){
			int p,q;
			cin>>p>>q;
			v.push_back({p,q});
		}
		double z=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				z+=sqrt(((v[i].first-v[j].first)*(v[i].first-v[j].first))+ ((v[i].second-v[j].second)*(v[i].second-v[j].second)));
			}
		}
		z*=2;
		z/=float(n);
		cout<<fixed<<setprecision(7)<<z;
	}
	return 0;
}