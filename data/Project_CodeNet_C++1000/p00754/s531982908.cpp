#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cctype>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

string s;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	while (1) {
		getline(cin, s);
		if (s == ".") break;
		string ans = [&] {
			int c1 = 0, c2 = 0;
			stack<char> sta;
			sta.push('#');
			rep (i, s.size()) {
				if (c1 < 0 || c2 < 0) return "no";
				switch (s[i]) {
					case '(':
						c1++;
						sta.push('(');
						break;
					case '[':
						c2++;
						sta.push('[');
						break;
					case ')':
						c1--;
						if (sta.top() == '[') return "no";
						sta.pop();
						break;
					case ']':
						c2--;
						if (sta.top() == '(') return "no";
						sta.pop();
						break;
					default:
						break;
				}
			}
			return (c1 == 0 && c2 == 0? "yes" : "no");
		}();
		cout << ans << endl;
	}
	return 0;
}