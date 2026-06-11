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

#define MAXN 10

int p[MAXN];
int d[MAXN];

vector<int> dig(int n) {
	vector<int> ret;
	if (!n) {
		ret.push_back(0);
		return ret;
	}
	while (n) {
		ret.push_back(n % 10);
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> p[i] >> d[i];
	}
	
	for (int i = 0; i <= 1000; i++) {
		vector<int> v = dig(i);
		if (v.size() != n) {
			continue;
		}
		bool ok = true;
		for (int j = 0; j < q; j++) {
			if (v[p[j] - 1] != d[j]) {
				ok = false;	
			}
		}
		if (ok) {
			cout << i << endl;
			return 0;
		}

	}
	cout << "-1" << endl;
	return 0;
}
