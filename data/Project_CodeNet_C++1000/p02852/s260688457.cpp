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

int mmove[MAXN];
string s;
int a[MAXN];
int n, m;

int main() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i <= n; i++) {
		a[i] = s[i] - '0';
	}
	int cur = max(0, n - m);
	while (a[cur]) {
		cur++;
	}
	mmove[n] = cur;
	
	for (int i = n - 1; i >= 0; i--) {
		int cur = i - m;
		if (a[cur] || (cur < 0)) {
			mmove[i] = mmove[i + 1];
		} else {
			mmove[i] = cur;
		}
	}
/*	for (int i = 0; i <= n; i++) {
		cerr << mmove[i] << " ";
	}
	cerr << endl;
*/
	vector<int> ret;
	int pos = n;
	while (pos != 0) {
		int nnext = mmove[pos];
		if (nnext >= pos) {
			cout << -1 << endl;
			return 0;
		}
		ret.push_back(pos - nnext);
		pos = nnext;
	}
	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;

	return 0;
}
