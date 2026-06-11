#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>

typedef  long long ll;
#define mop 1000000007
#define mop2 998244353

using namespace std;

int main() {
	ll a, b, n;
	cin >> a >> b >> n;
	if (n < b) {
		cout << a * n / b - a * (n / b) << endl;
	}
	else {
		cout << a * (b - 1) / b << endl;
	}
} 