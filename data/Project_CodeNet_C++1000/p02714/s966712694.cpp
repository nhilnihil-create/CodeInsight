#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

int n;

#define MAXN (1 << 12)

int lleft[3];
int rright[3];
int a[MAXN];

map<char, int> codes;

int f(int l[3], int r[3]) {
	return (l[0] * r[1] + l[1] * r[0] + l[0] * r[2] + l[2] * r[0] + l[1] * r[2] + l[2] * r[1]);
}

int main() {
	cin >> n;
	string s;
	cin >> s;
	codes['R'] = 0;
	codes['G'] = 1;
	codes['B'] = 2;
	for (int i = 0; i < n; i++) {
		rright[codes[s[i]]]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cur = codes[s[i]];
		rright[cur]--;
		int l[3];
		int r[3];
		for (int j = 0; j < 3; j++) {
			l[j] = 0;
			r[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			if (j != cur) {
				l[j] += lleft[j];
				r[j] += rright[j];
			}
		}
		ans += f(l, r);
		int shift = 1;
		int cnt = 0;
		while (true) {
			int lpos = i - shift;
			int rpos = i + shift;
			if ((lpos < 0) || (rpos >= n)) {
				break;
			}
			if ((s[lpos] != s[i]) && (s[rpos] != s[i]) && (s[lpos] != s[rpos])) {
				cnt++;
			}
			shift++;
		}
		ans -= cnt;
		lleft[cur]++;
	}
	cout << ans << endl;
	return 0;
}
