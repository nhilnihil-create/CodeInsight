#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int k, n;
	cin >> k >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> q(n);
	ll s = 0;
	for (int i = 0; i < n - 1; i++) {
		q[i] = v[i + 1] - v[i];
		s = s + q[i];
	}

	q[n - 1] = k - v[n - 1] + v[0];
	s = s + q[n - 1];
	int p = *max_element(q.begin(), q.end());

	cout << s - p << endl;

}