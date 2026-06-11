#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const int MOD = 1e9 + 7;
using namespace std;
typedef long long ll;

map<ll, int> mp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k == 1) cout << 0 << endl;
	else cout << n - k << endl;
	return 0;
}