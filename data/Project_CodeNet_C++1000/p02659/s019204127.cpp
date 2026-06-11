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
	ll a;
	string b;
	cin >> a >> b;
	
	ll base = 100;
	ll bs = 0;
	for(int i = 0; i < (int)b.size(); ++i) {
		if( b[i] == '.' ) continue;
		
		if( b[i] != '0' ) bs += base * (int)(b[i] - '0');
		
		base /= 10;
	}
	
	cout << (a * bs) / 100 << endl;
	
	return 0;
}
