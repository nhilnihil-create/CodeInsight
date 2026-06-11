#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
priority_queue<pair<ll, int> >que;
ll A[MAXN + 5], B[MAXN + 5]; int n;
int lst(int x) {return x == 1 ? n : x - 1;}
int nxt(int x) {return x == n ? 1 : x + 1;}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", &A[i]);
	for(int i=1;i<=n;i++) {
		scanf("%lld", &B[i]);
		que.push(make_pair(B[i], i));
	}
	ll ans = 0;
	while( !que.empty() ) {
		pair<ll, int>t = que.top(); que.pop();
		int x = t.second;
		if( B[x] == A[x] ) continue;
		ll p = B[lst(x)] + B[nxt(x)];
		if( B[x] - p < A[x] ) {
			puts("-1");
			return 0;
		}
		else {
			ll del = (B[x] - A[x]) / p;
			ans += del, B[x] -= del * p;
			que.push(make_pair(B[x], x));
		}
	}
	printf("%lld\n", ans);
}