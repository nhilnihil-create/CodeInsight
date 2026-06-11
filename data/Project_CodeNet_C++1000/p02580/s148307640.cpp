#define _CRT_SECURE_NO_WARNINGS 1

#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define rep(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; i--)
#define mem(a) memset(a,0,sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const LL INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int maxn = 3e5 + 7;

int head[maxn << 1];
struct Edge {
	int to,next;
} edge[maxn << 1];
int tot;

void init() {
	memset(head,-1,sizeof(head));
	tot = 0;
}

void addedge(int u,int v) {
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

map<int,int>cntx,cnty;
pii a[maxn];

int main() {
	fast_io;
	int n,m,num;
	cin >> n >> m >> num;
	int maxx = 0, maxy = 0;
	rep(i,1,num) {
		int x,y;
		cin >> x >> y;
		a[i].first = x, a[i].second = y;
		cntx[x]++, cnty[y]++;
		maxx = max(maxx, cntx[x]), maxy = max(maxy, cnty[y]);
	}
	int numx = 0, numy = 0;
	for(auto temp: cntx) {
		if(temp.second == maxx) numx++;
	}
	for(auto temp: cnty) {
		if(temp.second == maxy) numy++;
	}
	int cnt = 0;
	rep(i,1,num) {
		if(cntx[a[i].first] == maxx && cnty[a[i].second] == maxy) cnt++;
	}
	if(numx * numy == cnt) cout << maxx + maxy - 1 << endl;
	else cout << maxx + maxy << endl;
	return 0;
}