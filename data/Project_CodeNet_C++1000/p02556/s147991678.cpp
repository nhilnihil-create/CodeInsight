#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long>q;
	vector<long long>p;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		q.push_back(x + y);
		p.push_back(y - x);
	}
	long long a = *max_element(q.begin(), q.end()) - *min_element(q.begin(), q.end());
	long long b = *max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end());
	cout << max(a,b);
	return 0;
}