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
	int n;
	string s;
	cin >> n >> s;
	
	for(int i = 0; i < (int)s.size(); ++i) {
		cout << (char)( ( (s[i] - 'A') + n ) % 26 + 'A');
	}
	
	cout << endl;
	
	return 0;
}
