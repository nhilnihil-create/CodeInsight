#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false);
using namespace std;

int main() {
	fast_io;
	int n; cin >> n;
	int a[n];
	int cont = 0;
	for(int i = 0; i < n; i++) {
		cin>> a[i];
	}
	
	for(int i = 1; i < n - 1; i++) {
		if((a[i] < a[i-1] && a[i] > a[i+1]) || (a[i] > a[i-1] && a[i] < a[i+1])) {
			cont++;
		}
	}
	cout << cont;
	return 0;
}