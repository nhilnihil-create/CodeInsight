#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <random>
#include <unordered_set>
//#include <set>
#include <queue>
using namespace std;
typedef long long ll;

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
	int N,K;
	cin >> N >> K;
	vector<int> a(N-1),b(N-1),cnt(N,0);
	for(int i=0;i<N-1;i++){
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
	}
	ll ans = 1 ,MOD = 1000000007;
	auto edge = leaf_to_root(a,b,0);
	reverse(edge.begin(),edge.end());
	for(auto e:edge){
		int p = e.first;
		int c = e.second;
		(ans *= K-cnt[p]-1) %= MOD;
		cnt[p]++;cnt[c]++;
	}
	cout << ans*K%MOD << endl;
}
