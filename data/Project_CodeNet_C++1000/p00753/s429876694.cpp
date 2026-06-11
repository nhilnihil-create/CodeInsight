#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <string>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define REG(i, a, b) for (int (i) = ((int)(a)); (i) < ((int)(b)); i++)
#define ALL(V) (V).begin(), (V).end()
#define PRINT(STR) cout << (STR) << endl

typedef long long ll;
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void calc(int n) {
	int count = 0;
	REG(i, n + 1, 2 * n + 1) {
		if (isPrime(i)) {
			count++;
		}
	}
	PRINT(count);
}

int main() {
	cin.tie(0); //対話型には使えない
	ios::sync_with_stdio(false); //printfと共には使えない
	int n;
	while (cin >> n, n != 0) {
		calc(n);
	}
	return 0;
}