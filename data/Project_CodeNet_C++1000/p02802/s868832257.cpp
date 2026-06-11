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

int p[MAXN];
int a[MAXN];

int main() {
	int n, m;
	cin >> n >> m;
	int ac = 0;
	int pen = 0;
	for (int i = 0; i < m; i++) {
		int prob;
		string s;
		cin >> prob >> s;
		if (!a[prob]) {
			if (s == "AC") {
				a[prob] = 1;
				ac++;
				pen += p[prob];
			} else {
				p[prob]++;
			}
		}
	}
	cout << ac << " " << pen << endl;
	return 0;
}
