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
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;

	long long r = 0, g = 0, b = 0;

	for (int i = 0;i < N;i++) {
		if (s[i] == 'R') r++;
		else if (s[i] == 'G')g++;
		else b++;
	}

	long long ans = r * g * b;

	if (ans == 0) {
		cout << ans << endl;
		return 0;
	}

	for (int i = 0;i < N;i++) {
		for (int j = i + 1;j < N;j++) {
			int k = j + j - i;
			if (k >= N)break;
			if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
				ans--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}