#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	string s;
	cin >> s;
	int count = 0;
	rep(i, s.size() - 1) {
		if (s[i] == s[i+1]) {
			count++;
		}
	}
	if (count > 0) {
		cout << "Bad" << endl;
	} 
	else {
      cout << "Good" << endl;
    }
} 