#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

const int MAX = 100002;
int PARENT[MAX] = {0};
int RANK[MAX] = {0};
int CHLDS[MAX] = {0}; //自分と同じグループのメンバ数。親の値のみ信用できる。

void init(int L){
	if(L<1) return;
	for(int i=0; i<L; i++){
		PARENT[i]=i;
		RANK[i]=0;
		CHLDS[i] = 1;
	}
}

int root(int x){
	if(x<0) return -1;
	if(PARENT[x]==x){
		return x;
	}
	else{
		int p = root(PARENT[x]);
		if(p != PARENT[x]){
			if(CHLDS[x] != 0){
				CHLDS[p] += CHLDS[x];
				CHLDS[x] = 0;
			}
			PARENT[x] = p;
		}
		return PARENT[x];
	}
}

int same(int x, int y){
	if(x==y) return 1;
	if(root(x)==root(y)){
		return 1;
	}
	else{
		return 0;
	}
}

void combine(int x, int y){
	if(x==y) return;

	int a = root(x);
	int b = root(y);
	if(a==b) return;

	if(RANK[x]<RANK[y]){
		PARENT[b] = a;
		CHLDS[a] += CHLDS[b];
		CHLDS[b] = 0;
	}
	else{
		PARENT[a] = b;
		if(RANK[x]==RANK[y]) RANK[x] += RANK[y];
		CHLDS[b] += CHLDS[a];
		CHLDS[a] = 0;
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	init(N);
	for(int i=0; i<M; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		combine(a, b);
	}
	map<int, int> m;
	for(int i=0; i<N; i++){
		m[root(i)] = 1;
	}
	printf("%d\n", (int)m.size()-1);
	return 0;
}