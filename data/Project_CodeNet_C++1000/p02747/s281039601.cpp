#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	string s;
	cin >> s;
	bool ok = true;
	if (s.size() == 1|| s.size()%2==1) {
		cout << "No" << endl;
		return 0;
	}
	
	rep(i, s.size()) {
		if (i % 2 == 0) {
			if (s[i] == 'h') continue;
			ok = false;
			break;
		}
		else {
			if (s[i] == 'i') continue;
			ok = false;
			break;
		}
	}
	if (ok)cout << "Yes" << endl;
	else cout << "No" << endl;
}