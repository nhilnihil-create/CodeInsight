#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

using namespace std;


int main() {
	cin.tie(0);
	
	ios::sync_with_stdio(false);
	while (1) {
		string s;
		getline(cin, s);
		if (s[0] == '.')break;
		stack<int> r;
		REP(i, s.size()) {
			if (s[i] == '(') r.push(1);
			else if (s[i] == '[') r.push(0);
			else if (s[i] == ')') {
				if (r.empty()||r.top()==0) {
					cout << "no" << endl;
					break;
				}
				else {
					r.pop();
				}
			}
			else if (s[i] == ']') {
				if (r.empty()||r.top()==1) {
					cout << "no" << endl;
					break;
				}
				else {
					r.pop();
				}
			}
			if (i == s.size() - 1) {
				if (r.empty() &&r.empty()) cout << "yes" << endl;
				else cout << "no" << endl;
			}
		}
		
	}
	return 0;
}