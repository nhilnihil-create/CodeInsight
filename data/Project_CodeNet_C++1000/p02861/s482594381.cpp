#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int factorial(int x) {
	int res = 1;
	for (int i = 1; i <= x; ++i) {
		res *= i;
	}
	return res;
}

struct Point {
	int x, y;
};

double dist(Point a, Point b) {
	return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))*1.0);	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int facs = factorial(n-1), fac = facs*n;
	vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	double total = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			total += (dist(a[i], a[j])*2*facs);
		}
	}
	cout << fixed << setprecision(9) <<  1.0*total/fac << endl;
	return 0;
}