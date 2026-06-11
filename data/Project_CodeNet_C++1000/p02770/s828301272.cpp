#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define f first
#define s second 
using namespace std;
const LL INF = (LL) 1e9 + 5;
const LL MOD = (LL) 1e9 + 7;
//const int MAXN = 200005;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	LL k, qn;
	cin >> k >> qn;
	
	vector<LL> d_origin(k);
	for (int i = 0; i < k; i++) {
		cin >> d_origin[i];
	}
	
	for (int i = 0; i < qn; i++) {
		LL n, x, m, sum = 0;
		vector<LL> d(d_origin);
		cin >> n >> x >> m;
		n--;
		
		LL zcnt = 0;
		for (LL &v : d) {
			v %= m;
			sum += v;
			zcnt += (v == 0);
		}
		
		LL s = x / m, fin = x + sum * (n / d.size()), zero = zcnt * (n / d.size());
		for (int i = 0; i < n % d.size(); i++) {
			fin += d[i];
			if (d[i] == 0) {
				zero++;
			}
		}
		
		LL t = fin / m;
		cout << n - (t - s) - zero << '\n';
	}

	return 0;
}