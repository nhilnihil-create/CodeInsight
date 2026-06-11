#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	map<double, pair<double, double>> mp;

	for (int i = 0; i < N; i++) {
		double x, y; cin >> x >> y;
		if (x == 0 && y == 0) { continue; }
		double t = atan2(y, x);
		if (mp.find(t) != mp.end()) {
			mp[t].first += x;
			mp[t].second += y;
		}
		else {
			mp.insert({ t, { x,y } });
		}
	}

	vector<double> theta;
	vector<pair<double, double>> point;
	for (auto itr = mp.begin(); itr != mp.end(); itr++) {
		point.push_back({ itr->second.first, itr->second.second });
		theta.push_back(itr->first);
	}

	double ans = 0;
	
	N = theta.size();

	for (int i = 1; i < N; i++) {
		point[i].first += point[i - 1].first;
		point[i].second += point[i - 1].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double x1 = point[j].first - point[i].first;
			double y1 = point[j].second - point[i].second;

			double x2 = point[N - 1].first - x1;
			double y2 = point[N - 1].second - y1;

			ans = max(ans, max(x1 * x1 + y1 * y1, x2 * x2 + y2 * y2));
		}
	}

	cout << setprecision(20) << sqrt(ans) << endl;

	return 0;
}