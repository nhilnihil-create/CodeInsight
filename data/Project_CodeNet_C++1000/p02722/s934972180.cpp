#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

map<ll, int> factor(ll x){
	map<ll, int> res;
	ll m=x;
	for(ll i=2; i*i<=x; i++){
		while(m%i==0){
			res[i]++;
			m/=i;
		}
	}
	if(m!=1) res[m]++;
	return res;
}

int main(){
	ll n;
	cin>>n;
	auto fa=factor(n);

	vector<int> fi(fa.size());
	vector<ll> fl;
	repit(it, fa) fl.push_back(it->first);
	ll cnt=0;
	while(1){
		bool ok=false;
		for(int d=0; d<fi.size(); d++){
			fi[d]++;
			if(fi[d]>fa[fl[d]]) fi[d]=0;
			else{
				ok=true;
				break;
			}
		}
		if(!ok) break;
		ll k=1;
		rep(i, fi.size()) rep(_, fi[i]) k*=fl[i];

		ll m=n;
		while(m%k==0) m/=k;
		m%=k;
		if(m==1) cnt++;
	}
	auto fb=factor(n-1);
	ll cnt2=1;
	repit(it, fb) cnt2*=(it->second+1);
	cnt2-=1;
	cnt+=cnt2;

	cout<<cnt<<endl;
	return 0;
}
