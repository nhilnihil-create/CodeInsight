// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long cnt = 0;
vector<int> g;

int shell(int n) {
	int m = 0;
	for (int i = 1;; i = i*3  + 1, m++) {
		if (i > n)break;
		g.push_back(i);
	}
	return m;
}

void insertionSort(int a[], int n, int g) {
	int i, j;
	for (i = g; i < n; i++) {
		j = i;
		int v = a[i];
		while (j-g >= 0 && a[j - g] > v) {
			a[j] = a[j - g];
			j -= g;
			cnt++;
		}
		a[j] = v;
	}

}


int main()
{
	int a[1000001];
	int m;
	int n, i, j;
	cin >> n;
	m = shell(n);
	for (i = 0; i < n; i++)
		cin>>a[i];

		cout << m << endl;
		for (i = m-1; i >=0; i--) {
			insertionSort(a, n, g[i]);
			cout << g[i];
			if(i)cout<< ' ';
		}
		cout << "\n" << cnt << endl;
		for (i = 0; i < n; i++)
			cout << a[i] << endl;
    return 0;
}


