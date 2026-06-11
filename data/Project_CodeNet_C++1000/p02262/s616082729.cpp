#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>
#include<utility>
#include<map>

using namespace std;

int a[1000000];

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> g;
	int h = 1;
	g.push_back(h);
	while (h * 3 + 1 < n) {
		h = h * 3 + 1;
		g.push_back(h);
	}
	for (int k = g.size() - 1; k >= 0; k--) {
		for (int i = g[k]; i < n; i++) {
			int v = a[i], j = i - g[k];
			while (j >= 0 && a[j] > v) {
				a[j + g[k]] = a[j];
				j -= g[k];
				cnt++;
			}
			a[j + g[k]] = v;
		}
	}
	cout << g.size() << endl;
	for (int i = 0; i < g.size(); i++) {
		if (i != 0)cout << " ";
		cout << g[g.size()-i-1];
	}
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++)cout << a[i] << endl;
	return 0;
}