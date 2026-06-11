#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int ans = 0, sum = 1;

	while (b > sum) {
		sum--;
		sum += a;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
