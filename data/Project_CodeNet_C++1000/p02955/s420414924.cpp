#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<P> decomp;
vector<int> divs;


void f(int i, int cv=1) {
	if (i == decomp.size()) {
		divs.push_back(cv);
		return;
	}
	int d, num;
	tie(d, num) = decomp[i];
	rep(j, num + 1) {
		f(i + 1, cv);
		cv *= d;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int tot = 0;
	rep(i, n) {
		cin >> a[i];
		tot += a[i];
	}
	for(int i = 2; i < 25000; i++) {
		int cnt = 0;
		while(tot % i == 0) {
			tot /= i;
			cnt++;
		}
		if (cnt) decomp.emplace_back(i, cnt);
	}
	if (tot != 1) decomp.emplace_back(tot, 1);
	f(0);
	sort(divs.begin(), divs.end());
	for(int i = divs.size() - 1; i >= 0; i--) {
		int d = divs[i];
		sort(a.begin(), a.end(),
			[&](int ai, int aj) {return ai % d < aj % d;});
		int t = k;
		int p = 0;
		while(p < a.size() && t >= a[p] % d) {
			t -= a[p] % d;
			p++;
		}
		t = k - t;
		while(p < a.size() && t >= d - a[p] % d) {
			t -= d - a[p] % d;
			p++;
		}
		if (p == a.size()) {
			cout << divs[i] << endl;
			return 0;
		}
	}
}
