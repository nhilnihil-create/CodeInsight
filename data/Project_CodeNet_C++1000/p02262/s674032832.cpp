#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
long long cnt = 0;
void setsort(vector<int>&, int);
void shell(vector<int>&, int, int);
int main() {
	int n;
	vector<int> t(1000001, 0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	setsort(t, n);
	for (int i = 0; i < n; ++i) {
		cout << t[i] << endl;
	}
	return 0;
}
void setsort(vector<int> &t, int n) {
	cnt = 0;
	long long m = 0, k = 0, num, h = 0;
	vector<int> g(n+1, 0);
	num = n - 1;
	for (int i = n / 2; i >= 1; i /= 2) {
		g[k++] = i;
		m++;
	}
	if (m == 0) {
		g[k++] = 1;
		m++;
	}
	for (int i = 0; i < m; ++i) {
		shell(t, n, g[i]);
	}
	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		cout << (i == 0 ? "" : " ") << g[i];
	}


	cout << endl << cnt << endl;
	return;
}
void shell(vector<int> &t, int n, int g) {
	int v, j;
	for (int i = g; i < n; ++i) {
		v = t[i];
		j = i - g;
		while (j >= 0 && t[j] > v) {
			t[j + g] = t[j];
			j = j - g;
			cnt++;
			t[j + g] = v;
		}
	}
	return;
}
