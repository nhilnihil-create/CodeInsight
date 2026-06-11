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
	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	//入力で与えられた符号が正、負でまとめておく
	vector<int> pos;
	vector<int> neg;

	for (int i = 1; i < n - 1; i++) {
		if (a[i] >= 0) {
			pos.push_back(a[i]);
		}
		else {
			neg.push_back(a[i]);
		}
	}

	//手順を記録する配列
	vector<pair<int, int>> res;

	int base=0;
	//右端と左端を核にして、+→-の順でまとめてくっつけたい
	//+があればひっくり返すので、初手が入れ替わる
	if (pos.size() > 0) {
		base =a[0]-a[n-1];
		res.push_back(make_pair(a[0], a[n - 1]));
	}
	else {
		base = a[n - 1] - a[0];
		res.push_back(make_pair(a[n - 1], a[0]));
	}

	//最終的に+にしたい分を一つ残してまとめて-側に突っ込む
	if (pos.size() > 0) {
		for (int i = 0; i < pos.size() - 1; i++) {
			res.push_back(make_pair(base, pos[i]));
			base -= pos[i];
		}

		//残しておいた最後の+で-をまとめてひっくり返す
		res.push_back(make_pair(pos[pos.size() - 1], base));
		base = pos[pos.size() - 1] - base;
	}
	

	//-にしたい分を全部くっつける
	for (int i = 0; i < neg.size(); i++) {
		res.push_back(make_pair(base, neg[i]));
		base -= neg[i];
	}

	//出力
	cout << base << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}

	return 0;
}
