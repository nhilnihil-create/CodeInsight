#include <bit>
#include <bitset>
#include <assert.h>
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
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 20)

int a[MAXN];
int b[MAXN];
int n, k;

void naive() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			b[j] = 0;
		}
		vector<int> lleft;
		vector<int> rright;
		for (int j = 0; j < n; j++) {
			lleft.push_back(max(0, j - a[j]));
			rright.push_back(min(n, j + a[j] + 1));
		}
		sort(lleft.begin(), lleft.end());
		sort(rright.begin(), rright.end());
		lleft.push_back(MAXN);
		rright.push_back(MAXN);
		int cur = 0;
		int lpos = 0;
		int rpos = 0;
		for (int j = 0; j < n; j++) {
//			for (int t = max(0, j - a[j]); t <= min(j + a[j], n - 1); t++) {
//				b[t]++;
//			}
			while (lleft[lpos] == j) {
				lpos++;
				cur++;
			}
			while (rright[rpos] == j) {
				rpos++;
				cur--;
			}
			b[j] = cur;
		}
		bool done = true;
		for (int j = 0; j < n; j++) {
			a[j] = b[j];
			if (a[j] != n) {
				done = false;
			}
		}
		if (done) {
			return;
		}
	}
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	naive();
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
