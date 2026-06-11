#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define mod 1000000007

int main() {
	ll h, w, m;
	ll hi, wi;
	ll maxh = -1;
	ll maxw = -1;
	ll ans;
	set <pair<int, int>>p;
	cin >> h >> w >> m;
	vector<int> vh(h);
	vector<int> vw(w);
	vector<int> buf1;
	vector<int> buf2;
	vector <pair<int, int>> a;
	rep(i, m) {
		cin >> hi >> wi;
		hi--;	wi--;
		vh[hi]++;
		vw[wi]++;
		p.emplace(hi, wi);
	}
	rep(i, h) {
		if (maxh < vh[i]) {
			maxh = vh[i];
			buf1.clear();
			buf1.push_back(i);
		}
		if (maxh == vh[i])buf1.push_back(i);
		
	}
	rep(i, w) {
		if (maxw < vw[i]) {
			maxw = vw[i];
			buf2.clear();
			buf2.push_back(i);
		}
		if (maxw == vw[i])buf2.push_back(i);
		
	}
	ans = maxh + maxw;
	
	bool b = false;
	for (int i : buf1)	for (int j : buf2) {
		if (p.count(pair<int, int> {i, j}))continue;
		cout << ans << endl;
		return 0;
	}
	ans--;

	cout << ans << endl;
	return 0;
}