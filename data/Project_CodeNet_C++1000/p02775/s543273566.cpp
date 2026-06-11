#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
#ifdef _DEBUG
#define dlog(str) cout << "====" << str << endl;
#else
#define dlog(str)
#endif
#define INF 999999999
#define MOD 1000000007
#define REP(i, n) for(int i = 0, i##_l = (n); i < i##_l; i++)
#define FOR(i, s, e) for(int i = s, i##_l = (e); i < i##_l; i++)
#define LLI long long int
#define _min(a, b) ((a < b) ? a : b)
#define _max(a, b) ((a < b) ? b : a)
#define chmax(a, b) a = _max(a, b)
#define chmin(a, b) a = _min(a, b)
#define bit(a, shift) ((a>>shift)&1))
#define pm(a) ((a) ? 1 : -1)
#define SORT(v) sort(v.begin(), v.end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
// int 2.14E±9    lli 9.2E±18    double 1.7E±380

int main() {
	string s;
	cin >> s;

	int n = s.size();
	vector<int> v(n + 2);

	REP(i, n) {
		v[i] = s[n - i - 1] - '0';
	}

	int list[10] = { 0,1,2,3,4,5,4,3,2,1 };

	int dp[2];

	int cnt = 0;
	REP(i, n + 1) {
		if (9 < v[i]) {
			v[i + 1]++;
			v[i] -= 10;
		}


		cnt += list[v[i]];
		if (5 < v[i] || (v[i] == 5 && 5 <= v[i + 1])) {
			v[i + 1]++;
		}
	}
	cout << cnt;



	return 0;
}