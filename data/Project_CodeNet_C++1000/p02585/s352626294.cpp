#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#define rep(i,n) for (int i=0;i<(n);++i)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> p(n),c(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>c[i];
	rep(i,n) p[i]--;
	ll ans = -1e18;
	rep(si,n){
		int x = si;
		vector<int> s;
		ll tot = 0;
		while(1){
			x = p[x];
			s.push_back(c[x]);
			tot += c[x];
			if(x == si) break;
		}
		int l = s.size();
		ll t = 0;
		rep(i,l){
			t += s[i];
			if(i+1 > k) break;
			ll now = t;
			if(tot > 0){
				ll e = (k-(i+1))/l;
				now += tot*e;
			}
			ans = max(ans,now);
		}
	}
	cout<<ans<<endl;
}