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

#define INF ((ll) 1e9)

int n, k, s;

int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		cout << s << " ";
	}
	for (int i = k; i < n; i++) {
		if (s > n) {
			cout << "1 ";		
		} else {
			cout << INF << " ";
		}
	}
	cout << endl;
	return 0;
}
