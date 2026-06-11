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
#define INF 1000000000000000009;
#define WARU 1000000007;

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

int main() {
	int N = 0;
	//bool ok = false;
	long long a[100005],K = 0, ans = 1, amari = 0, memo = 0;
	cin >> K;
	if (K % 2 == 0) {
		cout << "-1" << endl;
		return 0;
	}
	amari = 7 % K;
	while (amari != 0&&ans<K+10) {
		amari = 7+(amari * 10) % K;
		amari = amari % K;
		//cout << amari << endl;
		ans++;
	}
	if (ans == K + 10) {
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}