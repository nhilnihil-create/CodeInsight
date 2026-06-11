#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long LL;
typedef pair<int, int> P;
int p[100006];
int main() {
	int n; cin >> n;
	vector<P>V;
	rep(i, n) {
		cin >> p[i];
		V.push_back(P(p[i], i));
	}
	sort(V.begin(), V.end());
	LL ans = 0;
	set<int>S1, S2;
	S1.insert(V[n-1].second);
	S2.insert(-V[n - 1].second);
	for (int i = n - 2; i >= 0; i--) {
		int q = V[i].second;
		auto i1 = S1.lower_bound(q);
		auto i2 = S2.lower_bound(-q);
		if (i1 != S1.end()) {
			LL l1, r1;
			if (i2 == S2.end())l1 = q + 1;
			else {
				l1 = q + (*i2);
			}
			auto i3 = S1.upper_bound(*i1);
			if (i3 == S1.end())r1 = n - (*i1);
			else r1 = (*i3) - (*i1);
			ans += l1*r1*(i + 1);
		}
		if (i2 != S2.end()) {
			LL l2, r2;
			if (i1 == S1.end())r2 = n -q;
			else {
				r2 = (*i1) - q;
			}
			auto i3 = S2.upper_bound(*i2);
			if (i3 == S2.end())l2 = 1-*i2;
			else l2 = (*i3) - (*i2);
			ans += l2*r2*(i + 1);
		}

		S1.insert(q);
		S2.insert(-q);
	}
	cout << ans << endl;
}