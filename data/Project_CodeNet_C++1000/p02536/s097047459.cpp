#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;

int fa[maxn];
int x, y, ans;

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) fa[i] = i;
	while(m--){
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x == y) continue;
		fa[x] = y, ans++;
	}
	printf("%d", n - 1 - ans);
}