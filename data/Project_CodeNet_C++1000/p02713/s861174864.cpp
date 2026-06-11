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

int gcd_2(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return(gcd_2(b, r));
	}
}
int gcd_3(int a, int b, int c) {
	return gcd_2(gcd_2(a, b), c);
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