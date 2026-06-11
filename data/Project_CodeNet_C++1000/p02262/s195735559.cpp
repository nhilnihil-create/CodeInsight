#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int num = 1000000;
const int m = 13;
int i, a[num], n, cnt = 0, G[m], j, p, cn = -1, v;
inline void insertionSort(int g) {
	for (i = g; i < n; i++) {
		int j = i - g;
		int v = a[i];
		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}
void shellSort() {
	int h = 1;
	for(int i = 0; h <= n; i++){
		G[i] = h;
		h = h * 3 + 1;
		cn++;
	}
	v = cn;	for (int i = cn; i >= 0; i--) {
		insertionSort(G[i]);
	}
}
int main(){
	cin >> n;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	shellSort();
	cout << v + 1 << endl;
	for (i = v; i >= 0; i--) {
		printf("%d", G[i]);
		if(i != 0)printf(" ");
	}
	cout << endl << cnt << endl;
	for(i = 0; i< n; i++)printf("%d\n", a[i]);
	return 0;
}