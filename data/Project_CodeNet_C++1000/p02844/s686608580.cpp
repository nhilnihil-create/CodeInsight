#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			for (int k = 0;k < 10;k++) {
				int flag_i = 0, flag_j = 0;
				for (int l = 0;l < s.length();l++) {
					if (flag_j == 1) {
						if (s[l] - 48 == k) {
							ans++;
							break;
						}
					}
					else {
						if (flag_i == 1) {
							if (s[l] - 48 == j) flag_j = 1;
						}
						else {
							if (s[l] - 48 == i) flag_i = 1;
						}
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
