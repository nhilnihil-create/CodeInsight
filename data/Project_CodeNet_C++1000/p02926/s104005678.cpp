#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	const double pi = atan2(0, -1);
	int N;
	cin >> N;
	vector<tuple<double, ll, ll>> V(N);
	ll x, y, xi = 0, yi = 0, r, maxr = 0;
	double theta, angle;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		theta = atan2(y, x);
		V[i] = make_tuple(theta, x, y);
	}
	sort(V.begin(), V.end());


	for (int i = 0;i < N;i++) {
		int b = -1;
		x = y = r = 0;
		for (int j = i;j < N;j++) {
			tie(ignore, xi, yi) = V[j];
			x += xi;y += yi;
			r = max(r, x * x + y * y);
		}
		for (int j = 0;j < i;j++) {
			tie(ignore, xi, yi) = V[j];
			x += xi;y += yi;
			r = max(r, x * x + y * y);
		}
		maxr = max(r, maxr);
	}
	printf("%.12f\n", sqrt(maxr));
}