#include <cstdio>
#include <iostream> 
#include <queue>
#define debug(...) //fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
inline char nc() {
//	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++; 
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
int n;
int a[maxn], b[maxn];
priority_queue<pii> q;
inline int f(int x, int y) {
	return x / y * y;
}
ll solve() {
	for(int i = 1; i <= n; ++i) {
		if(b[i] < a[i]) return -1;
		if(b[i] == a[i]) continue;
		q.push(make_pair(b[i], i));
	}
	ll cnt = 0;
	while(!q.empty()) {
		pii now = q.top(); q.pop();
		int x = now.se - 1; if(now.se == 1) x = n;
		int y = now.se + 1; if(now.se == n) y = 1;
		if(b[now.se] < b[x] + b[y]) return -1;
		int delt = (b[now.se] - a[now.se]) / (b[x] + b[y]); cnt += delt;
		b[now.se] -= delt * (b[x] + b[y]);
		if(b[now.se] < a[now.se]) return -1;
		if(b[now.se] > a[now.se]) q.push(make_pair(b[now.se], now.se));
	}
	return cnt;
}
int main() {
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		read(b[i]);
	}
	printf("%lld\n", solve());
	return 0;
}