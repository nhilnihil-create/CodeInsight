#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
long n;
long a[1000000];
long G[100];
long cnt;
// O(g)
void insertionSort(long g){
	for (long i = g; i < n; ++i){
		long v = a[i];
		long j = i - g;
		while (j >= 0 && a[j] > v){
			a[j + g] = a[j];
			j = j - g;
			++cnt;
		}
		a[j + g] = v;
	}
}
void shellSort(){
	G[0] = 1;
	for (int i = 1; i < 100; ++i) G[i] = 2*G[i-1];
	int m=1;
	for (int i = 0; i < 100; ++i){
		if (G[i]>n) break;
		m = i + 1;
	}
	for (int i = m-1; i >=0; --i) insertionSort(G[i]);
	cout << m << '\n';
	for (int i = m-1; i >=0; --i){
		if (i != m-1) cout << ' ';
		cout << G[i];
	}
	cout << '\n';
	cout << cnt << '\n';
}

int main(){
	cin >> n;
	for (long i = 0; i < n; ++i) cin >> a[i];
	shellSort();
	for (long i = 0; i < n; ++i){
		cout << a[i] << '\n';
	}
}