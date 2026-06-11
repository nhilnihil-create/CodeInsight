#include <bits/stdc++.h>
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
#define _all(arg) begin(arg),end(arg)

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0; }
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0; }

using namespace std;

static string pad[10] = {
	"",
	".,!? ",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

int main(void){
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		string res = "";
		int r=0, c=0;
		rep(i,s.size()) {
			if(s[i] == '0') {
				if(r==0) {
					c=0;
					continue;
				}
				else {
					c%=pad[r].size();
					res += pad[r][c];
					r=0, c=0;
				}
			}
			else {
				if(s[i]-'0' == r) c++;
				else r = s[i]-'0';
			}
		}
		cout << res << endl;
	}
	return 0;
}