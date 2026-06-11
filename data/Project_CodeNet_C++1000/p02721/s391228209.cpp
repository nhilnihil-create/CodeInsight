#include <bits/stdc++.h>

using namespace std;

int main(int, char**) {
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	queue<int> que;
	stack<int> stk;
	for (int i=0; i<n; i++) {
		if (s.at(i) == 'o') {
			que.push(i + 1);
			stk.push(i + 1);
		}
	}
	vector<int> l;
	int cnt = 0;
	int lp = -2*n;

	while (cnt<k) {
		int now = que.front();
		que.pop();
		if (now - lp > c) {
			l.push_back(now);
			cnt++;
			lp = now;
		}
	}

	vector<int> r;
	cnt = 0;
	int rp = 3*n;
        while (cnt<k) {
                int now = stk.top();
                stk.pop();
                if (rp - now > c) {
                        r.push_back(now);
                        cnt++;
                        rp = now;
                }
        }
        for (int i=0; i<k; i++) {
                int a = l.at(i);
                int b = r.at(k-i-1);
                if (a==b) cout << a << endl;
        }

        return 0;
}
