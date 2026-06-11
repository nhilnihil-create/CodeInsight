#include <stdio.h>
#include <iostream>
#include <utility>
using namespace std;

int shellSort(int a[], int n);
int insertionSort(int a[], int n, int g);

int main(void)
{	
	int n;
	cin >> n;
	
	int *a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	
	shellSort(a, n);
	
	delete[] a;
	
	return 0;
}

int shellSort(int a[], int n)
{	
	int *g = new int[n];
	g[0] = 1;
	int m, i = 1;
	while (1) {
		g[i] = g[i-1] * 3 + 1;
		if (g[i] > n) {
			m = i;
			break;
		}
		i++;
	}
	
	cout << m << endl;
	
	int cnt = 0;
	for (int i = m - 1; i >= 0; i--) {
		cout << g[i];
		if (i > 0) cout << " ";
		else cout << endl;
		
		cnt += insertionSort(a, n, g[i]);
	}
	
	delete[] g;
	
	cout << cnt << endl;
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	
	return cnt;
}

int insertionSort(int a[], int n, int g)
{
	int cnt = 0;
	for (int i = g; i < n; i++) {
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v) {
			a[j+g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}