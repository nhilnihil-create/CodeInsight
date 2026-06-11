#include <bits/stdc++.h>  
 
using namespace std;
 
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string, int> P;

int main() {
	int h, w;
	while(scanf("%d %d", &h, &w), h && w) {
		rep(i, h) {
			rep(j, w) printf("#");
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}