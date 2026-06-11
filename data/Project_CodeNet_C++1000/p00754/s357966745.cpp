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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

const double EPS = 1e-10;


int main() {
	string str;
	stack<int> st;

	

	while(getline(cin, str) && str != ".") {
		bool successed = true;
		st.push(2);

		FOR(i, 0, str.size()) {
			char c = str[i];

			if(c == '(') {
				st.push(0);
			} else if(c == '[') {
				st.push(1);
			} else if(c == ')') {
				if(st.top() != 0) {
					successed = false;
					break;
				}
				st.pop();
			} else if(c == ']') {
				if(st.top() != 1) {
					successed = false;
					break;
				}
				st.pop();
			}
		}

		if(successed) {
			if(st.top() == 2) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		} else {
			cout << "no" << endl;
		}

	}

	return 0;
}