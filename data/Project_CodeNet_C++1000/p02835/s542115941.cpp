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
	int a, b, c;
	cin >> a >> b >> c;
	
	if( a + b + c >= 22 ) cout << "bust" << endl;
	else cout << "win" << endl;
	
	return 0;
}
