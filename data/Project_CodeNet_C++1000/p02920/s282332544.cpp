#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int p = 1 << n;
	vector<int> s(p);
	for (int i = 0; i < p; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end(), greater<int>());
	vector<bool> b(p, false);
	b[0] = true;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		queue<int> q;
		for (int j = 0; j < p; j++) {
			if (b[j]) q.push(s[j]);
			else if (q.empty()) ;
			else if (q.front() > s[j]) {
				b[j] = true;
				q.pop();
			}
		}
		if (!q.empty()) {ans = false; break;}
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}