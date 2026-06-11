#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int h, w, m;
	cin >> h >> w >> m;
	vector<int>hp(h), wp(w);
	set<pi>s;
	rep(i, m) {
		int y, x;
		cin >> y >> x;
		y--, x--;
		hp[y]++;
		wp[x]++;
		s.insert(pi(y, x));
	}
	int mh=0, mw=0;
	rep(i, h)mh = max(mh, hp[i]);
	rep(i, w)mw = max(mw, wp[i]);

	vector<int>hm, wm;
	rep(i, h)if (hp[i] == mh)hm.push_back(i);
	rep(i, w)if (wp[i] == mw)wm.push_back(i);

	ll ans = mh + mw;

	for(int y:hm)for(int x:wm) {
		if(s.count(pi(y,x)))continue;
		cout << ans << endl;
		return 0;
	}
	cout << --ans << endl;

	return 0;
}

