#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
long long cnt;
int l;
int a[N];
int n;
vector<int> G;

void insertionSort(int a[], int n, int g){
	for (int i = g; i < n; i++) {
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shellSort(int a[], int n) {
	//????????????G={1,4,13,40,121,364,1093,...}
	int h = 1;
	while(1)
	{
		if (h > n) break;
		G.push_back(h);
		h = 3 * h + 1;
	}
	for (int i = G.size() - 1; i >= 0; i--) {
		insertionSort(a, n, G[i]);
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cnt = 0;
	
	shellSort(a, n);

	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--) {
		cout << G[i];
		if (i) cout << " ";
	}
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}