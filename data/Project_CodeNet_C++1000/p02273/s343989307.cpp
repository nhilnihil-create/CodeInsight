#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void solve(){
	int n, an = 2;
	cin >> n;
	vector<pair<double, double> > k_old, k_new;
	k_old.push_back(make_pair(0, 0));
	k_old.push_back(make_pair(100, 0));
	for (int j = 1; j < n + 1; j++){
		for (int i = 0; i < an - 1; i++){
			double x = k_old[i].first;
			double y = k_old[i].second;
			double z = k_old[i + 1].first;
			double w = k_old[i + 1].second;
			double xn = (sqrt(3) / 6) * (y - w + sqrt(3) * (z - x));
			double yn = (sqrt(3) / 6) * (z - x + sqrt(3) * (w - y));
			k_new.push_back(k_old[i]);
			k_new.push_back(make_pair(x + (z - x) / 3, y + (w - y) / 3));
			k_new.push_back(make_pair(x + xn, y + yn));
			k_new.push_back(make_pair(x + 2 * (z - x) / 3, y + 2 * (w - y) / 3));
		}
		k_new.push_back(k_old.back());
		k_old = k_new;
		k_new.clear();
		an = 4 * an - 3;
	}
	for (int i = 0; i < k_old.size(); i++) cout << fixed << setprecision(8) << k_old[i].first << " " << k_old[i].second << endl;
}

signed main(){
	solve();
}