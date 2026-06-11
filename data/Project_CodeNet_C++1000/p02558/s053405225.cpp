#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
int n, q, t, u, v;
int main(){
	scanf("%d%d", &n, &q);
	dsu d(n);
	rep(i,q){
		scanf("%d%d%d", &t, &u, &v);
		if(t == 0) d.merge(u, v);
		else puts(d.leader(u) == d.leader(v) ? "1" : "0");
	}
}