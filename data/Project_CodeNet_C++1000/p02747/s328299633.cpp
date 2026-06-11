#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.size() % 2 != 0) {
		cout << "No" << endl;
		return 0;
	}
	int cnt = 0;
	bool flag = true;
	rep(i, s.size()) {
		if (cnt % 2 == 0) {
			if (s[i] != 'h') flag = false;
		}
		else {
			if (s[i] != 'i') flag = false;
		}
		cnt++;
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}