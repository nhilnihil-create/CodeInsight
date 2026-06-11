#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	ll k;
	cin>>n>>k;
	vector<int> a(n), f(n);
	rep(i, n) cin>>a[i];
	rep(i, n) cin>>f[i];

	sort(a.rbegin(), a.rend());
	sort(f.begin(), f.end());
	ll l=-1, r=1000000000000;//l ng  r ok
	while(l+1<r){
		ll m=(l+r)/2;
		ll c=0;
		rep(i, n) c+=max((ll)0, (ll)a[i]-m/f[i]);
		if(c<=k) r=m;
		else l=m;
	}

	cout<<r<<endl;
	return 0;
}
