#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	string s;
	cin >> s;
	deque<char> dq;
	for(char c : s)
		dq.push_back(c);
	bool st = 0;
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(x == 1)
			st ^= 1;
		else {
			int y;
			cin >> y;
			char c;
			cin >> c;
			if(y == 1) {
				if(st)
					dq.push_back(c);
				else
					dq.push_front(c);
			}
			else {
				if(st)
					dq.push_front(c);
				else
					dq.push_back(c);
			}
		}
	}
	string ans;
	for(char c : dq)
		ans += c;
	if(st)
		reverse(ans.begin(), ans.end());
	cout << ans;
}
