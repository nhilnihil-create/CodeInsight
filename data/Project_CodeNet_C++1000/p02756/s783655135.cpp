#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int ct = 0;
	int q; cin >> q;
	int t;
	int f;
	char c;
	queue<char> r;
	queue<char> l;
	stack<char> s;
	while (q--) {
		cin >> t;
		if (t == 1) ct += 1;
		if (t == 2) {
			 cin >> f;
			 cin >> c;
			 if ((f + ct) % 2) l.push(c);
			 else r.push(c);
		}
	}
	if (ct % 2) {
		reverse(str.begin(), str.end());
		while (!r.empty()) {
			s.push(r.front());
			r.pop();
		}
		while (!s.empty()) {
			cout << s.top() << flush;
			s.pop();

		}
		cout << str << flush;
		while (!l.empty()) {
			cout << l.front() << flush;
			l.pop();
		}
	}
	else {
		while (!l.empty()) {
			s.push(l.front());
			l.pop();
		}
		while (!s.empty()) {
			cout << s.top() << flush;
			s.pop();

		}
		cout << str << flush;
		while (!r.empty()) {
			cout << r.front() << flush;
			r.pop();
		}
	}

	cout << endl;


	return 0;
}
