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

string rev(string s) {
	string t = "";
	RREP(i, s.size()) {
		t += s[i];
	}
	return t;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m;
	cin >> m;
	REP(i, m) {
		int cnt = 0;
		set<string> a;
		string s;
		cin >> s;
		FOR(i,1, s.size()) {
			string s1 = s.substr(0, i);
			string s2 = s.substr(i);
			if (a.insert(s1 + s2).second) cnt++;
			if (a.insert(s2 + s1).second) cnt++;
			if (a.insert(s1 + rev(s2)).second) cnt++;
			if (a.insert(rev(s2) + s1).second) cnt++;
			if (a.insert(rev(s1) + s2).second) cnt++;
			if (a.insert(s2 + rev(s1)).second) cnt++;
			if (a.insert(rev(s1) + rev(s2)).second) cnt++;
			if (a.insert(rev(s2) + rev(s1)).second) cnt++;
 		}
		cout << cnt << endl;
	}
	return 0;
}