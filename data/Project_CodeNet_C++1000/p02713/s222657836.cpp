#include <iostream>
#include<vector>
#include<array>
#include<cmath>
#include <algorithm>

using namespace std;
#define ull unsigned long long
int gcd(int a, int b) {
	if (a % b == 0) {	
			return b;
	}
	else {
			return gcd(b,a%b);
	}
}
int main() {
	// 初期処理(iostream軽くする)
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				temp += gcd(gcd(i, j), gcd(i, k));
			}
		}
	}

	cout << temp;
	return 0;
}