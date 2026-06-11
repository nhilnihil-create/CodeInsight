#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main(){
	long long n, p;
	string s;
	long long ans = 0;
	cin >> n >> p >> s;
	if (p == 2) {
		for (long long i = 0; i < n; i++) {
			if (int(s[i] - '0') % 2 == 0) {
				ans += i + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (p == 5) {
		for (long long i = 0; i < n; i++) {
			if (int(s[i] - '0') % 5 == 0) {
				ans += i + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	long long co[10000] = { 0 };
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		int c = int(s[i] - '0');
		int x = n - i - 1;
		int a = 10;
		while (x > 0) {
			if ((x & 1) == 1) {
				c = c * a % p;
			}
			a = a * a % p;
			x >>= 1;
		}
		sum = (sum + c) % p;
		co[sum % p]++;
	}
	co[0]++;
	for (int j = 0; j < 10000; j++) {
		ans += co[j] * (co[j] - 1) / 2;
	}
	cout << ans << endl;
}