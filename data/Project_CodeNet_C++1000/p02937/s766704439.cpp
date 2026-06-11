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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string s, t;
	cin >> s >> t;
	
	int slen = (int)s.size();
	int tlen = (int)t.size();
	
	vector< vector<int> > p(26);
	
	for(int i = 0; i < slen; ++i) {
		int c = (int)(s[i] - 'a');
		p[c].push_back(i);
	}
	
	for(auto& c : t) {
		int x = (int)(c - 'a');
		
		if( p[x].empty() ) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	ll ans = 0LL;
	for(int i = 0; i < tlen; ++i) {
		int x = (int)(t[i] - 'a');
		int v = lower_bound(p[x].begin(), p[x].end(), ans % slen) - p[x].begin();
		
		if( v == (int)p[x].size() ) {
			ans = ((ans + slen - 1) / slen) * slen;
			
			int v2 = lower_bound(p[x].begin(), p[x].end(), ans % slen) - p[x].begin();
			
			ans += p[x][v2] - ans % slen;
		} else {
			ans += p[x][v] - ans % slen;
		}
		
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
