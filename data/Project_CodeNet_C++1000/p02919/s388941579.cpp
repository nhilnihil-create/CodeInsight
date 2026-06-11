#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);




	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		p.at(i-1)=pair<ll, ll>(a, i);
	}
	sort(p.begin(),p.end(),greater<pair<int,int>>());

	multiset<ll> mset;
	mset.insert(0); mset.insert(0);
	mset.insert(n + 1); mset.insert(n + 1);
	long long ans=0;
	
	for (auto q : p) {
		auto v = q.first;
		auto i = q.second;
		auto r = mset.lower_bound(i);
		auto rr = next(r);
		auto l = prev(r);
		auto ll = prev(l);
		mset.insert(i);

		ans += ((*l - *ll)*(*r - i) + (*rr - *r)*(i - *l))*v;
	}
	cout << ans << endl;
}