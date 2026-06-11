#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
signed main() {
	int n, m, no = 0; string s; cin >> n >> m >> s;
	vector<int>cnt;
	reverse(s.begin(), s.end());
	for (int h = 0; h <= n; h++) {
		for (int i = min(n - h, m); i > 0; i--) {
			if (s[h + i] == '0') { 
				if (h + i == n) {
					cnt.push_back(i);
					reverse(cnt.begin(),cnt.end());
					for (int j = 0; j < cnt.size(); j++) {
						if (j == 0) { cout << cnt[j]; }
						else { cout << ' ' << cnt[j]; }
					}
					cout << endl;
					return 0;
				}
				cnt.push_back(i); h = h + i - 1; no = 1;
				break;
			}
		}
		if (no == 0) { cout << -1 << endl; return 0; }no = 0;
	}
	return 0;
}