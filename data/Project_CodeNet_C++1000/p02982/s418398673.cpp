#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;

double calc(int a[], int b[]) {
	double x = 0;
	for(int i = 0; i < k; i++) {
		x += pow(a[i] - b[i] , 2);
	}
	return sqrt(x);
}

void solve() {

	
	cin >> n >> k;
	int mat[n][k];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			cin >> mat[i][j];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			double d = calc(mat[i], mat[j]);
			if((int) d == d) {
				cnt++;
			}
		}
	}
	cout << cnt;

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}