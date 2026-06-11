#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
#define N 5005
int P[N], C[N];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> P[i];
	for(int i = 1; i <= n; i++) cin >> C[i];
	ll Ans = -INF;
	rep(i, 1, n) {
		int p = i;
		ll cnt = 0, len = 0, allsum = 0, sum = 0;
		while(1) {
			++len;allsum += C[p];p = P[p];
			if(p == i)break;
		}
		cnt = 0, sum = 0;
		while(1) {
			++cnt;sum += C[p];
			if(cnt > k)break;
			ll num = (k - cnt) / len;
			ll scr = sum + max(0LL, allsum) * num;
			Ans = max(Ans, scr);
			
			p = P[p];if(p == i)break;
		}
		
	}
	cout << Ans << endl;
	return 0;
} 