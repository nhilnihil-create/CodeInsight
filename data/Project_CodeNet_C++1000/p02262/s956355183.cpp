//============================================================================
// Name        : ALDS1_2_D.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int cnt,m;
vector<int> G;

void insertionSort(vector<int>& a, int n, int g) {
	for(int i=g; i<n; ++i) {
		int j,v=a[i];
		for(j=i-g; j>=0 && a[j]>v;j-=g) {
			swap(a[j+g],a[j]);
			++cnt;
		}
		a[j+g]=v;
	}
}

void shellSort(vector<int>& a,int n) {
	cnt = 0;
	m=0;
	int d=n;
	while(1) {
		d=2*d/3;
		if(d<2) {
			G.push_back(1);
			++m;
			break;
		}
		G.push_back(d);
		++m;
	}
	for(int i=0; i<m; ++i) {
		insertionSort(a, n, G[i]);
	}
}

int main() {
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	shellSort(a,n);
	cout << m << endl;
	for(int i=0; i<m-1; ++i) {
		cout << G[i] << " ";
	}
	cout << G[m-1] << endl;
	cout << cnt << endl;
	for(auto x : a) {
		cout << x << endl;
	}
	return 0;
}