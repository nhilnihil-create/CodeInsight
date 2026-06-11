#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vec;
typedef pair<int, int> P;
#define rep(n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define out(a) cout << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define INF 100000000

int arr[999999] = { 0 };

void Eratosthenes(int N) {
	for (int i = 0; i <= N; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i <= sqrt(N); i++) {
		if (arr[i]) {
			for (int j = 0; i * (j + 2) <= N; j++) {
				arr[i *(j + 2)] = 0;
			}
		}
	}
	int res = 0;
	for (int i = (N/2)+1; i <= N; i++) {
		if (arr[i]) {
			res++;
		}
	}
	cout << res << endl;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		Eratosthenes(2 * n);
	}
	return 0;
}

