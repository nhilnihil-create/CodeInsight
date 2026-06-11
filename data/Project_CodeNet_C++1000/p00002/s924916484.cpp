#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	int a, b, n = 0;
	while (cin >> a >> b) {
		a += b;
		for (int i = 0; a > 0; i++) {
			a = a / 10;
			n++;
		}
		if (n == 0) {
			n = 1;
		}
		cout << n << endl;
		n = 0;
	}
}