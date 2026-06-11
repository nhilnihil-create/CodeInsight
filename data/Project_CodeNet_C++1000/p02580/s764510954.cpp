#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);	
    int h, w, m, r, c;
    cin >> h >> w >> m;
    vector<int> r_cnt(h), c_cnt(w);
    vector<pair<int, int>> targets(m);
    for (int i = 0; i < m; ++i) {
    	cin >> r >> c; --r, --c;
    	r_cnt[r]++;
    	c_cnt[c]++;
    	targets[i] = {r, c};
    }
   	int b_row = (max_element(r_cnt.begin(), r_cnt.end()) - r_cnt.begin());
   	int b_col = (max_element(c_cnt.begin(), c_cnt.end()) - c_cnt.begin());
   	ll cnt = 0;
   	if (r_cnt[b_row] > c_cnt[b_col]) {
   		cnt += r_cnt[b_row];
	   	vector<int> nc_cnt = c_cnt;
	   	for (auto t: targets)
	   		if (t.first == b_row) nc_cnt[t.second]--;
	   	cnt += *max_element(nc_cnt.begin(), nc_cnt.end());

   	} else {
   		cnt = c_cnt[b_col];
	   	vector<int> nr_cnt = r_cnt;
	   	for (auto t: targets)
	   		if (t.second == b_col) nr_cnt[t.first]--;
	   	cnt += *max_element(nr_cnt.begin(), nr_cnt.end());
   	}
   	cout << cnt << '\n';
    return 0;
}