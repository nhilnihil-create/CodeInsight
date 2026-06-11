#include<stdio.h>
#include <iomanip>
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include <random>
#include <chrono>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int main() {
	int n,ans=0,old=-2;
	cin >> n;
	vector<int> a(n + 1,0), b(n + 1), c(n + 1);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	rep(i, n-1) {
		cin >> c[i];
	}
	for (int i = 0; i < n ;i++) {
		
		if (old + 1 == a[i]) {
			ans += c[old-1];
		}
		ans += b[a[i]-1];
		old = a[i];
	}

	cout << ans;
}