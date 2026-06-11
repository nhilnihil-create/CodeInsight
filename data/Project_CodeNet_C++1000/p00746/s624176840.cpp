
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

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define loop(n) FOR(i,0,n)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

int main() {

	while (true) {
		int n; cin >> n;

		if (n == 0)return 0;

		if (n == 1) {
			cout << 1 << " " << 1 << endl;
		}

		map<int,pair<int,int>> m;

		m[0].first = 0;
		m[0].second = 0;

		for (int i = 1; i < n; i++) {
			
			int target;
			int direct;

			cin >> target >> direct;

			int y,x;

			y = m[target].first;
			x = m[target].second;

			if (direct == 0) {
				x--;
			}

			if (direct == 1) {
				y++;
			}

			if (direct == 2) {
				x++;
			}

			if (direct == 3) {
				y--;
			}

			m[i].first = y;
			m[i].second = x;

		}

		int minx = INF;
		int miny = INF;

		int maxx = -1000;
		int maxy = -1000;

		for (auto p : m) {
			if (p.second.first < miny) {
				miny = p.second.first;
			}

			if (p.second.second < minx) {
				minx = p.second.second;
			}

			if (p.second.first > maxy) {
				maxy = p.second.first;
			}

			if (p.second.second > maxx) {
				maxx = p.second.second;
			}
		}

		int width = maxx - minx+1;
		int height = maxy - miny+1;

		cout << width << " " << height << endl;
	}

	return 0;
}

