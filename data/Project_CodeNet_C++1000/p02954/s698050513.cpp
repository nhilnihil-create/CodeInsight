#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char s[N];
int idxR[N], idxL[N], addup[N];
typedef pair<int, char> PII;
stack<PII> stk;
int main() {
	cin >> s;
	for (int i = 0; s[i]; i ++) {
		if (s[i] == 'R') stk.push({i, s[i]});
		else {
			while(stk.size()) {
				auto t = stk.top();
				idxR[t.first] = i - t.first;
				stk.pop();
			}
		}
	}
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i --) {
		if (s[i] == 'L') stk.push({i, s[i]});
		else {
			while(stk.size()) {
				auto t = stk.top();
				idxL[t.first] = t.first - i;
				stk.pop();
			}
		}
	}

	for (int i = 0; s[i]; i ++) {
		if (s[i] == 'R') {
			if (idxR[i] % 2 == 0) addup[i + idxR[i]] ++;
			else addup[i + idxR[i] - 1] ++;
		}
		else {
			if (idxL[i] % 2 == 0) addup[i - idxL[i]] ++;
			else addup[i - idxL[i] + 1] ++;
		}
	}
	
	for (int i = 0; i < len; i ++) cout << addup[i] << " ";
}