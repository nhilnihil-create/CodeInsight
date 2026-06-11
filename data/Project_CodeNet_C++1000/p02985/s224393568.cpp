#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 100009
#define LL long long
#define INF 0x3f3f3f3f
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
const int K = 1e9 + 7;
LL ans = 1;
int k, mark[N], head[N], tot = 0, ding[N], lian[N], dist[N];
struct link{
	int to, nxt;
}l[N * 2];
void add1(int a, int b){
	l[++tot].to = b;
	l[tot].nxt = head[a];
	head[a] = tot;
}
void add(int a, int b){
	add1(a, b), add1(b, a);
}
void dfs(int x, int f){
	ans = 1ll * ans * (k - ding[f]) % K;
	for(int i = head[x]; i; i = l[i].nxt)
		ding[l[i].to]++;
	ding[x]++;
	for(int i = head[x]; i; i = l[i].nxt)
		if(l[i].to != f) dfs(l[i].to, x);	
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, a, b;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		add(a, b);
		lian[a]++, lian[b]++;
	}
	for(int i = 1; i <= n; i++){
		if(lian[i] + 1 > k){
			cout << 0 << endl;
			return 0;
		}
	}
	ding[0] = 0;
	dfs(1, 0);
	cout << ans;
	return 0;
}
