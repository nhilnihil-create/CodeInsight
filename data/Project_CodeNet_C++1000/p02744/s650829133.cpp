#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	set<string>ss;
	queue<string>qs;
	qs.push("a");
	while (qs.size() > 0) {
		string x = qs.front();
		if (x.length() == n) ss.insert(x);
		else {
			int y = 0;
			for (int i = 0; i < x.length(); i++)y = max(y, x.at(i) - 'a');
			for (int i = 0; i <= y+1; i++) {
				char w = 'a' + i;
				string z = x + w;
				qs.push(z);
			}
		}
		qs.pop();
	}
	for (auto a : ss) {
		cout << a << endl;
	}

}