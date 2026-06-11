#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
#include<deque>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

const string base = "()[]";
set<char> st;

int solve(string s) {
	string a = "";
	for (char c : s) {
		if (st.count(c)) a.push_back(c);
	}

	stack<char> sta;

	for (char c : a) {
		if (c == '(' || c == '[') sta.push(c);
		else {
			if (sta.empty()) return 0;
			if (c == ')' && sta.top() != '(') return 0;
			if (c == ']' && sta.top() != '[') return 0;
			sta.pop();
		}
	}

	return sta.empty();
}


int main() {
	for (auto c : base) st.insert(c);
	string s;
	while (getline(cin,s), s != ".") {
		cout << (solve(s) ? "yes" : "no") << endl;
	}
}
