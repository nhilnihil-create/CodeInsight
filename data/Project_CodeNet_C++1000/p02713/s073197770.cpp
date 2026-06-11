#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
#include<queue>
#include<map>
using namespace std;

int gcd_2(int A, int B) {
	int a = A;
	int b = B;
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int gcd_3(int A, int B, int C) {
	int a = A;
	int b = B;
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	a = b;
	b = C;
	r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	int K;
	cin >> K;
	int ans = 0;
	for (int a = 1; a <= K; a++) {
		for (int b = 1; b <= K; b++) {
			for (int c = 1; c <= K; c++) {
				ans += gcd_3(a, b, c);
			}
		}
	}
	cout << ans << endl;
	return 0;
}