#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

ll n,m,q;
vector<ll> a,b,c,d;
ll ans = -1;

void dfs( int s, int now, vector<int> v ){
	if( now == n+1 ){
		ll cnt = 0;
		rep(i,q){
			if( v.at(b.at(i)) - v.at(a.at(i)) == c.at(i) ){
				cnt += d.at(i);
			}
		}
		ans = max(ans,cnt);
		return;
	}
	for(int i=s;i<=m;++i){
		vector<int> tmp = v;
		tmp.emplace_back(i);
		dfs(i,now+1,tmp);
	}
}

int main(){
	cin >> n >> m >> q;
	a.resize(q,0);
	b.resize(q,0);
	c.resize(q,0);
	d.resize(q,0);
	rep(i,q){
		cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
		a.at(i)--;
		b.at(i)--;
	}
	vector<int> v = {};
	dfs(1,1,v);
	cout << ans << endl;
	return 0;
}