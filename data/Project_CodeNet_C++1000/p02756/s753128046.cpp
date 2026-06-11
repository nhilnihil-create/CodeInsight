#include <bits/stdc++.h>
using namespace std;

int tt;
string s;

int main() {
	cin >> s >> tt;
	bool reverse = false;
	deque<char> q;
	for (char c : s) {
		q.push_back(c);
	}
	for (int i=0; i<tt; i++) {
		int t;
		cin >> t;
		if (t == 1)
			reverse ^= 1;
		else {
			int f; char c;
			cin >> f >> c;
			if ((f == 1 && !reverse) || (f == 2 && reverse))
				q.push_front(c);
			else
				q.push_back(c);
		}
	}
	if (reverse) {
		while (!q.empty()) {
			cout << q.back();
			q.pop_back();
		}
	}
	else {
		while (!q.empty()) {
			cout << q.front();
			q.pop_front();
		}
	}
}