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
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	string s;
	cin >> s;
	
	if( s.size() % 2 == 1 ) {
		cout << "No" << endl;
		return 0;
	}
	
	int cnt = 0;
	for(int i = 0; i < s.size() - 1; ++i) {
		if( s[i] == 'h' && s[i + 1] == 'i' ) {
			cnt++;
		}
	}
	
	if( cnt == s.size() / 2 ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
