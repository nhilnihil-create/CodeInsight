#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	string s;
	cin >> s;
	int i = 0;
	int cnt = 0;
	while (i < s.size()-1) {
		if (s[i] != s[i + 1]) {
			cnt++;
			i++;
		}
		else {
			i += 3;
			if (i > s.size()) {
				cnt += 1;
			}
			else {
				cnt += 2;


			}
		}
		
	}
	if (i == s.size() - 1)cnt++;
	cout << cnt << endl;
		return 0;
}