#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)

vector< pair<int,int> > leaf_to_root(const vector<int> &u,const vector<int> &v,const int root){
	// return <parent,child>
	int yet = 1000000000;
	vector<int> d(u.size()+1,yet);
	vector< pair<int,int> > res;
	queue<int> Q;
	Q.push(root);
	d[root] = 0;
	vector< vector<int> > G(u.size()+1);
	for(int i=0;i<u.size();i++){
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	while( Q.size() ){
		int now = Q.front();
		Q.pop();
		for(auto nex:G[now]){
			if(d[nex]!=yet)continue;
			d[nex] = d[now] + 1;
			Q.push(nex);
			res.push_back( make_pair(now,nex) );
		}
	}
	reverse(res.begin(), res.end());
	return res;
}


int main(){

	int N;
	ll ans=1,K,MOD=1000000007;
	cin >> N >> K;
	vector<int> x(N-1),y(N-1);
	FOR(i,0,N-1) cin >> x[i] >> y[i];
	FOR(i,0,N-1) x[i]--,y[i]--;

	auto route = leaf_to_root(x,y,0);
	ans = K;
	vector<int> cnt(N,0);
	reverse(route.begin(),route.end());
	for(auto a:route){
		int p = a.first;
		int c = a.second;
		ll count = K - cnt[p] - 1;
		cnt[p]++;cnt[c]++;
		( ans *= count ) %= MOD;
	}

	cout << ans << endl;
}
