#include <bits/stdc++.h>
using namespace std;
long long n, m, v, p;
int a[100001];

vector <int> study;
int main() {
	cin >> n >> m >> v >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long st = 0;
	long long en = n - 1;
	while (st < en) {
		study.clear();
		int mid = (st + en) >> 1;
		for (int i = 0; i < n; i++) {
			if (i != mid)
				study.push_back(a[i]);
		}
		//cout << "THING: " << endl;
		//for (int i = 0; i < study.size(); i++) {
		//	cout << study[i] << ' ';
		//} cout << endl;
		long long cost = 0;
		for (int i = study.size() - 1; i >= 0; i--) {
			if (study.size() - i <= p - 1) {
				cost += m;
			}
			else {
				if (study[i] > a[mid] + m) {
					cost = -1;
					break;
				}
				cost += min(m, a[mid] + m - study[i]);
			}
			//cout << "ITERATION " << i << " " << cost << endl;
		}
		//cout << mid << ' ' << cost << '\n';
		if (cost >= m * (v - 1)) {
			en = mid;
		} else
			st = mid + 1;
	}
	cout << n - en << '\n';
	
}