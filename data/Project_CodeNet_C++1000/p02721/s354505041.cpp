#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	// L[x]: x回目に働くのはL[x]日以降
	// R[x]: x回目に働くのはR[x]日以前
	int L[200001], R[200001];
	int now = 0;
	for (int i = 1; i <= k; i++) {
		while (s[now] == 'x') now++;
		L[i] = now;
		now += c + 1;
	}
	now = n - 1;
	for (int i = k; i >= 1; i--) {
		while (s[now] == 'x') now--;
		R[i] = now;
		now -= c + 1;
	}
	for (int i = 1; i <= k; i++) {
		if (L[i] == R[i]) cout << L[i] + 1 << endl;
	}
}