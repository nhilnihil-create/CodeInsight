#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
int n, d[N];

int main() {
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		d[x]++;
	}
	
	int ans = 0;
	for(int i = 1; i <= 1e5; i++) {
		d[i] += d[i-1];
		if(d[i] == n/2) ans++;
		if(d[i] > n / 2) break;
	}
	cout << ans << endl;
	return 0;	
} 