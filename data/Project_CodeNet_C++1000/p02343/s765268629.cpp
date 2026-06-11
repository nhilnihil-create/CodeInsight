#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int n, q;
int rank[10000], par[10000];

void init(){
	rep(i,n) par[i] = i;
	rep(i,n) rank[i] = 0;
}

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(par[x]);
	y = find(par[y]);
	if(x == y) return;
	
	if(rank[x] < rank[y]){
		par[x] = y;
	} else{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

int same(int x, int y){
	return find(x) == find(y);
}

int main(){
	scanf("%d%d",&n,&q);
	init();
	rep(i,q){
		int com, x, y;
		scanf("%d%d%d",&com,&x,&y);
		if(com == 0){
			unite(x,y);
		} else {
			printf("%d\n",same(x,y));
		}
	}
}