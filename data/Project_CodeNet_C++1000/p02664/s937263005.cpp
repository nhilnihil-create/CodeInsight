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
	string s;
	cin >> s;
	for (auto i : s) {
		if (i == '?') {
			cout << 'D';
		}
		else {
			cout << i;
		}
	}
	cout << endl;
}