#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = ll(1e9) + 7;
const int INF = int(1e9);


int main() {
	cin.sync_with_stdio(false);
	bool f[250000] = {};
	reps(i, 2, 250000) {
		if (f[i] == 1)continue;
		reps(j, i + 1, 250000) {
			if (j%i == 0)f[j] = 1;
		}
	}
	int cnt = 0;
	while (1) {
		int Q;
		cin >> Q;
		if (Q == 0)return 0;
		int cnt1 = 0, cnt2 = 0;
		reps(i,2, Q * 2+1) {
			if (f[i] == 0) {
				if (i <= Q)cnt1++;
				cnt2++;
			}
		}
		cout << cnt2 - cnt1 << endl;
	}
	return 0;
}

