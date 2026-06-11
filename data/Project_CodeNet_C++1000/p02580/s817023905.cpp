#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int H, W, M;
	cin >> H >> W >> M;
	int r[H], c[W];
	rep(i,H) r[i] = 0;
	rep(i,W) c[i] = 0;
	map<pair<int,int>,bool> b;

	vector<int> hv, wv;
	rep(i,M) {
		int hh, ww;
		cin >> hh >> ww;
		hh--; ww--;
		hv.push_back(hh); wv.push_back(ww);
		r[hh]++; c[ww]++;
		b[make_pair(hh,ww)] = true;
	}
	set<int> h(hv.begin(), hv.end()), w(wv.begin(), wv.end());

	int max_h = 0, max_w = 0;
	vector<int> hm, wm;
	for (int hh : h) {
		if (r[hh] > max_h) {
			max_h = r[hh];
			hm.clear();
			hm.push_back(hh);
		}
		else if (r[hh] == max_h) hm.push_back(hh);
	}
	for (int ww : w) {
		if (c[ww] > max_w) {
			max_w = c[ww];
			wm.clear();
			wm.push_back(ww);
		}
		else if (c[ww] == max_w) wm.push_back(ww);
	}

	int ans = max_h + max_w;
	bool flag = true;
	for (int hh : hm) {
		for (int ww : wm) {
			if (b[make_pair(hh,ww)]==false) {
				flag = false;
				break;
			}
			if (!flag) break;
		}
	}

	if (flag) ans--;
	cout << ans << endl;

		return 0;
}
