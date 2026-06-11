/*
 * ALDS1_2_D.cpp
 *
 *  Created on: Apr 25, 2018
 *      Author: 13743
 */

#include<iostream>

using namespace std;

int cnt = 0;

void insertionSort(int* a, int n, int g) {
	for(int i=g; i<n; i++) {
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v) {
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = v;
	}
}

int main() {
	int n;
	cin >> n;
	int a[1000000];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int g[100];
	int m=0;
	int gg = 1;
	while(m < 100 && gg <= n) {
		g[m] = gg;
		m++;
		gg = 3*gg + 1;
	}
	
	for(int i=0; i<m; i++) {
		insertionSort(a, n, g[m-1-i]);
	}
	
	cout << m << endl;
	cout << g[m-1];
	for(int i=1; i<m; i++) {
		cout << " " << g[m-1-i];
	}
	cout << endl;
	cout << cnt << endl;
	for(int i=0; i<n; i++) {
		cout << a[i] << endl;
	}
}



