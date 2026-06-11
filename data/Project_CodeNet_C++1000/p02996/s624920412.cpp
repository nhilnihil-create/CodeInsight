#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int n;
	cin >> n;
	vector<P>p(n);
	int task, deadline;
	for (int i = 0; i < n; i++) {
		cin >> task >> deadline;
		p[i].first = deadline;
		p[i].second = task;
	}
	sort(p.begin(), p.end());
	ll worksum = 0;
	for (int i = 0; i < n; i++) {
		worksum += p[i].second;
		if (worksum > p[i].first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}