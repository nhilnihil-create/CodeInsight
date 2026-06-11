#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int k, x;
	cin >> k >> x;
	
	for(int i = x - k + 1; i < x + k; ++i) {
		cout << i << " ";
	}
	
	cout << endl;
	
	return 0;
}
