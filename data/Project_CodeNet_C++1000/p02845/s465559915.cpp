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
long long ha[100010] = { 0 };
int main() {
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			ans = ans * (ha[a - 1] - ha[a]) % 1000000007;
		}
		else {
			ans = ans * (3 - ha[a]) % 1000000007;
		}
		ha[a]++;
	}
	cout << ans << endl;
}