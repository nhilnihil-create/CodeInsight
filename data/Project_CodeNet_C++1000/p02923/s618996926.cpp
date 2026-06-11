#include<iostream>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
#include<cmath>
#include<map>
#include <limits>
# include <iomanip>
#include <queue>
#define INF 1000000009;

using namespace std;
int gcd(int a, int b) {
	while (a % b != 0) {
		int c = 0;
		c = a % b;
		a = b;
		b = c;
	}
	return  b;
}
int kaizyo(int a) {
	long long ans = 1;
	for (int i = a; i > 0; i--) {
		ans *= i;
		ans = ans % 1000000007;
		//cout << ans << endl;
	}
	ans = ans % 1000000007;
	return ans;
}

int main() {
	int a = 0, right = 0, left = -1; int counto = 0, ans = 0;
	vector <int> H;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> right;
		if (left >= right) {
			counto++;
			
		}
		else{
			ans = max(ans, counto);
			counto = 0;
		}
		left = right;
	}
	ans = max(ans, counto);
	cout << ans << endl;
	return 0;
}

