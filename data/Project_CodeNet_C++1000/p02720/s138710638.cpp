#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(int x) {
	int cnt = 1;
	queue<ll>Q;
//	if(x <= 9)printf("%d\n", x);
	for(int i = 1; i <= 9; i++) {
		Q.push(i);
	}
	while(1) {
		ll t = Q.front();Q.pop();
		if(cnt == x) {
			printf("%lld\n", t);
			return ;
		} 
//		printf("%d\n", t);
		if(t % 10 == 9) {
			Q.push(t * 10 + 8);
			Q.push(t * 10 + 9);
		}
		else if(t % 10 == 0) {
			Q.push(t * 10);
			Q.push(t * 10 + 1);
		}
		else {
			for(ll j = t % 10 - 1;j <= t % 10 + 1; j++) {
				Q.push(t * 10 + j);
			}
		}
		++cnt;
	}
}
int main() {
	int k;
	cin >> k;
	bfs(k);
	return 0;
} 