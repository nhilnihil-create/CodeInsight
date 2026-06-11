#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;
const ll INF=1e10;
const double PI=acos(-1.0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	ll n,m,x;
	cin>>n>>m>>x;
	vector<ll> c(n);
	vector<vector<ll>> a(n,vector<ll> (m));
	for(int i=0;i<n;i++){
		cin>>c[i];
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	ll k=1<<n,ans=LLONG_MAX;
	for(ll i=1;i<k;i++){
		bitset<12> b(i);
		ll sum=0;
		vector<ll> skill(m);
		for(int l=0;l<n;l++){
			if(!b[l]) continue;
			sum+=c[l];
			for(int j=0;j<m;j++) skill[j]+=a[l][j];
		}
		bool ok=true;
		for(int j=0;j<m;j++){
			if(skill[j]<x){
				ok=false;
				break;
			}
		}
		if(ok) ans=min(ans,sum);
	}
	cout<<(ans^LLONG_MAX?ans:-1);
}
