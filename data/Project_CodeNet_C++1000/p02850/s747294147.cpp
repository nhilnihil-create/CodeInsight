#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;


const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<vector<int>> G(n);
	vector<PI> vp;
	rep(i,n-1){
		int a, b; cin >> a >> b;
		a--; b--;
		G.at(a).push_back(b);
		G.at(b).push_back(a);
		vp.push_back(make_pair(a, b));
	}
	map<PI, int> M; //<頂点,頂点>で使う色
	queue<int> que;
	que.push(0);
	vector<int> cs(n,0); //その頂点の親(ある頂点に対するbfsでの一個手前の頂点)を結ぶ辺の色
	vector<int> seen(n, 0);
	seen.at(0) = 1;
	int K = 0; //辺の数の最大値
	while(!que.empty()){
		int v = que.front(); que.pop();
		if(K < (int)G.at(v).size()) K = G.at(v).size();
		int color = 1;
		for(int nv: G.at(v)){
			if(seen.at(nv)) continue;
			seen.at(nv) = 1;
			if(color == cs.at(v)) color++; //vはbfsの一個前の辺でこのcolorを使っちゃってる
			cs.at(nv) = M[make_pair(v, nv)] = M[make_pair(nv, v)] = color;
			color++;
			que.push(nv);
		}
	}
	cout << K << endl;
	for(auto p: vp){
		cout << M[p] << endl;
	}
}