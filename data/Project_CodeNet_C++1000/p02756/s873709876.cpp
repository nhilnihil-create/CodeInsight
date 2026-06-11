#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	string s;
	int Q;
	cin >> s>>Q;
	deque<char> q;
	rep(i, s.size())q.push_back(s[i]);
	//cout << q.front() << endl;
	int sw(1);
	rep(i, Q) {
		int buf;
		cin >> buf;
		if (buf == 1)sw *= -1;
		if (buf == 2) {
			int f;
			char c;
			cin >> f >> c;
			if (f == 1) {
				if (sw == 1)q.push_front(c);
				else q.push_back(c);
			}
			else {
				if (sw == -1)q.push_front(c);
				else q.push_back(c);
			}
		}
	}
	int qs = q.size();
	rep(i, qs) {
		
		if (sw == 1) {
			cout << q.front(); q.pop_front();
		}
		else {
			cout << q.back(); q.pop_back();
		}
		//cout << endl;
	}
	return 0;
}