#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <stack>

using namespace std;

#define Getsign(n) ((n > 0) - (n < 0))
#define QWERTYR(c) (c == 'y' || c == 'u' || (c >= 'h' && c <= 'p') ?	true : false)
typedef vector<int> Ivec;
typedef pair<int, int> pii; // (cst, to)

int main() {
	int n, m;
	map<string, bool> IDs;
	scanf("%d", &n);
	for (int i = 0; n > i; i++) {
		char str[11];
		scanf("%s", str);
		IDs[string(str)] = true;
	}
	scanf("%d", &m);
	bool state = false;
	for (int i = 0; m > i; i++) {
		char str[11];
		scanf("%s", str);
		if (IDs[string(str)]) {
			state = 1 - state;
			printf("%sed by %s\n", state ? "Open" : "Clos", str);
		}
		else {
			printf("Unknown %s\n", str);
		}
	}

	return 0;
}