#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < 1000; ++i) {
		ostringstream os;
		os << setfill('0') << setw(3) << i;
		string str = os.str();
		int pos = 0;
		for (int j = 0; j < n; ++j) {
			if (str[pos] == s[j]) pos++;
			if (pos == 3) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
