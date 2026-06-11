#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP(i, 0, (n))
#define REP(i, a, n) for(int i=a; i<(n); i++)

int main() {
	int m; cin >> m;
	rep(_, m) {
	    set<string> t;
	    string s; cin >> s;
	    rep(i, s.size()) {
	        t.insert(s);

	        string a = s.substr(0, i);
	        string b = s.substr(i, s.size());
	        string ra(a);
	        string rb(b);
	        reverse(ra.begin(), ra.end());
	        reverse(rb.begin(), rb.end());
	        
	        t.insert(a + b);
	        t.insert(b + a);
	        t.insert(ra + b);
	        t.insert(b + ra);
	        t.insert(a + rb);
	        t.insert(rb + a);
	        t.insert(ra + rb);
	        t.insert(rb + ra);
	    }

	    cout << t.size() << endl;
	}
}

