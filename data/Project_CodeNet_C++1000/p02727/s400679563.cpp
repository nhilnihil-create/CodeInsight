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

typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (100100)

priority_queue<int, std::vector<int>, std::greater<int> > q1, q2;

int aa[MAXN], bb[MAXN], cc[MAXN];

void fillq(priority_queue<int, std::vector<int>, std::greater<int> > & q, int a[MAXN], int n, int s) {
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < min(n, s); i++) {
		q.push(a[i]);	
	}
	while (q.size() != s) {
		q.push(0);
	}
}

int main() {
	int x, y;
	int a, b, c;
	cin >> x >> y >> a >> b >> c;
	for (int i = 0; i < a; i++) {
		cin >> aa[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> bb[i];
	}
	for (int i = 0; i < c; i++) {
		cin >> cc[i];
	}
	fillq(q1, aa, a, x);
	fillq(q2, bb, b, y);
	
	sort(cc, cc + c);
	reverse(cc, cc + c);
	for (int i = 0; i < c; i++) {
		int f1 = q1.top();
		int f2 = q2.top();
		if (f1 < f2) {
			if (cc[i] > f1) {
				q1.pop();
				q1.push(cc[i]);
			}
		} else {
			if (cc[i] > f2) {
				q2.pop();
				q2.push(cc[i]);
			}
		}
	}
	ll ret = 0;
	while (!q1.empty()) {
		ret += q1.top();
		q1.pop();
	}
	while (!q2.empty()) {
		ret += q2.top();
		q2.pop();
	}
	cout << ret << endl;
	return 0;
}
