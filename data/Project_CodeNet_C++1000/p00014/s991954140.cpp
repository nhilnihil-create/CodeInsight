#include <bits/stdc++.h>  
 
using namespace std;
 
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1e9 + 7
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main() {
	int N;
	while(cin >> N) {
		int d = N;
		int cnt = 1;
		int ans = 0;
		while(1) {
			if(d * cnt == 600 - N) {
				ans += d * cnt * d * cnt * N;
				break;
			}
			ans += d * cnt * d * cnt * N;
			++cnt;
		}
		cout << ans << endl;
	}
	return 0;
}