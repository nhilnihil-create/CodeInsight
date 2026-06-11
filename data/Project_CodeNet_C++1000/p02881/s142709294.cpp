#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

vector<P> factor(ll n){
	map<ll, int> ma;
	for(ll i=2; i*i<=n; i++){
		while(n%i==0){
			ma[i]++;
			n/=i;
		}
	}
	if(n!=1) ma[n]++;
	vector<P> ps;
	for(auto p : ma) ps.push_back(p);
	return ps;
}

int main(){
	ll n;
	cin>>n;

	auto ps=factor(n);
	int m=ps.size();
	vector<int> ci(m);
	ll mn=LLONG_MAX;
	while(1){
		ll a=1;
		rep(i, m) rep(j, ci[i]) a*=ps[i].first;
		ll b=n/a;
		mn=min(mn, a+b-2);

		bool br=false;
		rep(i, m){
			ci[i]++;
			if(ci[i]>ps[i].second) ci[i]=0;
			else break;
			if(i==m-1) br=true;
		}
		if(br) break;
	}

	cout<<mn<<endl;

	return 0;
}
