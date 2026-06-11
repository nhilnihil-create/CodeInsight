
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

int main() {
	string s; cin >> s;
	int l = s.size();
	vector<vector<LL>> dp(l+1, vector<LL>(13));
	//初期化
	if (s[0] != '?') {
		dp[0][s[0] - '0'] = 1;
	}
	else {
		for (int i = 0; i < 10; i++) {
			dp[0][i] = 1;
		}
	}

	for (int i = 1; i < l; i++) {
		for (int j = 0; j < 13; j++) {
			//数字はそのまま置くしかない
			if (s[i] != '?') {
				int v = (s[i] - '0');
				int r = (j * 10 + v) % 13;
				dp[i][r] = (dp[i][r]+dp[i - 1][j]+MOD)%MOD;
			}
			else {
				for (int k = 0; k < 10; k++) {
					int r = (j * 10 + k) % 13;
					dp[i][r] = (dp[i][r] + dp[i - 1][j] + MOD) % MOD;
				}
			}
		}
	}

	cout << dp[l-1][5] << endl;

	return 0;

}