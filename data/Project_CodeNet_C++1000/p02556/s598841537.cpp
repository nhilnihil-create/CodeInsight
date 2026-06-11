#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<pair<long long, long long>> point(n);
	for(int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;
	sort(point.begin(), point.end());
	long long prefix_mx_below = - (point[0].first + point[0].second);
	long long prefix_mx_above = - point[0].first + point[0].second;
	long long res = LONG_LONG_MIN;
	for(int i = 1; i < n; i++){
		res = max({res, prefix_mx_below+point[i].first+point[i].second, 
						prefix_mx_above+point[i].first-point[i].second});
		prefix_mx_below = max(prefix_mx_below, - point[i].first - point[i].second);
		prefix_mx_above = max(prefix_mx_above, - point[i].first + point[i].second);
	}
	cout << res << '\n';
	return 0;
}

