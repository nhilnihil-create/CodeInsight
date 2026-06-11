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
	long long n;
	cin >> n;
	long long n1 = n - 1;
	long long ans = 0;
	for (long long i = 1; i * i <= n1; i++) {
		if (n1 % i == 0) {
			if (i != 1) {
				ans++;
			}
			if ((n1 / i) != 1 && (n1 / i) != i) {
				ans++;
			}
		}
	}
	for (long long j = 1; j * j <= n; j++) {
		if (n % j == 0) {
			long long n2 = n;
			if (j != 1) {
				while (n2 % j == 0) {
					n2 /= j;
				}
				if (n2 % j == 1) {
					ans++;
				}
			}
			n2 = n;
			long long n3 = n / j;
			if (n3 != j) {
				while (n2 % n3 == 0) {
					n2 /= n3;
				}
				if (n2 % n3 == 1) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}