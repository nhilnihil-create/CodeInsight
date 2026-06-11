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
#include <fstream>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string s;
	cin >> s; 
	
	int n = (int)s.size();
	int cnt = 0;
	vector<int> ans(n, 0);
	
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'R' ) {
			cnt++;
		} else {
			ans[i] += cnt / 2;
			ans[i - 1] += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	
	cnt = 0;
	
	for(int i = n - 1; i >= 0; --i) {
		if( s[i] == 'L' ) {
			cnt++;
		} else {
			ans[i] += cnt / 2;
			ans[i + 1] += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i];
		
		if( i < n - 1 ) cout << " ";
	}
	
	cout << endl;
	
	return 0;
}
