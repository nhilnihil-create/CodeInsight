#include "bits/stdc++.h"

using namespace std;

const int maxn = 2e5 + 5;

long long bit[maxn];

void update(int pos, long long val) {
	while (pos < maxn) {
		bit[pos] += val;
		pos += (pos & -pos);
	}
}

void update(int l, int r, long long val) {
	update(l, val);
	update(r + 1, -val);
}

long long query(int pos) {
	long long sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= (pos & -pos);
	}
	return sum;
}

int n;
long long d;
long long A;
long long arr[maxn];
long long coor[maxn];

signed main() {
	cin >> n >> d >> A;
	vector < pair <int, int> > vec;
	for (int i = 1; i <= n; i++) {
		int cor, val;
		cin >> cor >> val;
		vec.push_back(make_pair(cor, val));
	}
	sort(vec.begin(), vec.end());
	vector <int> coordinates;
	for (int i = 1; i <= n; i++) {
		arr[i] = vec[i - 1].second;
		coor[i] = vec[i - 1].first;
		coordinates.push_back(vec[i - 1].first);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long sum = query(i);
		if (sum >= arr[i]) {
			continue;
		}
		long long dif = arr[i] - sum;
		long long need = dif / A + (dif % A > 0); 
		ans += need;
		int l = i;
		int r = upper_bound(coordinates.begin(), coordinates.end(), coor[i] + 2 * d) - coordinates.begin();
		update(l, r, A * need);
	}
	cout << ans << endl;
}