#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Point {
	int x, y;
};

double dist(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


void solve() {

	int n;
	cin >> n;
	int arr[n];
	Point p[n];
	for(int i = 0; i < n; i++) {
		arr[i] = i;
		cin >> p[i].x >> p[i].y;
	}
	int cnt = 0;
	double total = 0;
	do {
		for(int i = 1; i < n; i++) {
			total +=  dist(p[arr[i]], p[arr[i - 1]]);
		}
		cnt++;
	}while(next_permutation(arr, arr + n));
	cout << setprecision(10);
	cout << total / (double)cnt;




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}