#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int q;
	cin >> q;

	deque <char> letters;
	bool initial = true;
	for (auto &c : s) {
		letters.push_back(c);
	}

	while (q--) {
		int op;
		cin >> op;

		if (op == 1) {
			initial ^= 1;
		}

		else {
			cin >> op;
			char now;
			cin >> now;
			if (op == 1) {
				if (initial) {
					letters.push_front(now);
				}
				else letters.push_back(now);
			}
			else {
				if (initial) {
					letters.push_back(now);
				}
				else letters.push_front(now);
			}
		}
	}

	if (initial) {
		while (letters.size()) {
			cout << letters.front();
			letters.pop_front();
		}
	}

	else {
		while (letters.size()) {
			cout << letters.back();
			letters.pop_back();
		}
	}

	return 0;
}
