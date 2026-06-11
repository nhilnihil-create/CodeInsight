#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EACH(t,i,c) for(t::iretator i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n-1)
const double EPS = 1e-10;
const double PI = acos(-1.0);
 
int main() {
	int N, M;
	
	while(cin >> N >> M, N) {
		vvi enemy(N, vi(2));
		int total = 0;

		REP(i, N) {
			cin >> enemy[i][1] >> enemy[i][0];
			total += enemy[i][0]*enemy[i][1];
		}
		sort(RALL(enemy));

		REP(i, N) {
			if(M-enemy[i][1] <= 0) {
				total -= M*enemy[i][0];
				break;
			} else {
				M -= enemy[i][1];
				total -= enemy[i][0]*enemy[i][1];
			}
		}

		cout << total << endl;
	}

	return 0;
}