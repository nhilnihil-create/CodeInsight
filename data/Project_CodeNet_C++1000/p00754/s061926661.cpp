#ifndef _WIN32
#include<iostream>
#endif // !_WIN32

#include<string>
#include<iomanip>
#include<vector>
#include<string>
#include<stack>
using namespace std;

#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()



int main() {
	string s;
	while (getline(cin, s), s != ".") {

		int n = s.size();
		vector<int> v;
		REP(i, n) {
			if (s[i] == '(')v.push_back(0);
			if (s[i] == ')')v.push_back(1);
			if (s[i] == '[')v.push_back(2);
			if (s[i] == ']')v.push_back(3);
		}
		string res=[&]() {
			stack<int> st;
			for (auto &it : v) {
				if (it & 1) {
					if (st.empty())return "no";
					if ((st.top() | 1) != it)return "no";
					st.pop();
				}
				else {
					st.push(it);
				}
			}
			if(st.empty())return "yes";
			else return "no";
		}();
		cout << res << endl;
	}

	return 0;
}