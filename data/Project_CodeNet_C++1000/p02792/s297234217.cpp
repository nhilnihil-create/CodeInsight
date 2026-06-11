#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int keta(int a) {
	int cnt = 1;
	while (a/10!= 0) {
		a /= 10;
		cnt++;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	int c[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k <= n; k++) {
				if (keta(k) == i && k % 10 == j)c[i][j]++;
			}
		}
	}
	
	int ans=0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			ans += c[i][j] * c[j][i];
		}
	}
	cout << ans << endl;
	return 0;

	
}