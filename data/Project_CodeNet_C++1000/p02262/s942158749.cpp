#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int n, a[1000010], cnt, m[100];
vector<int> v;
void insertionSort(int *a, int n, int g) {
	rep2(i,g,n) {
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v) {
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
}
void shellSort(int *a, int n) {
	cnt = 0;
	int h = 1;
	while(h <= n) {
		h = 3 * h + 1;
	}
	while(h) {
		h = (h - 1) / 3;
		if(h) v.push_back(h);
	}
	rep(i,v.size()) {
		insertionSort(a, n, v[i]);
	}
}
int main() {
	cin >> n;
	rep(i,n) {
		cin >> a[i];
	}
	shellSort(a, n);
	cout << v.size() << endl;
	rep(i,v.size() - 1) {
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
	cout << cnt << endl;
	rep(i,n) {
		cout << a[i] << endl;
	}
	return 0;
}