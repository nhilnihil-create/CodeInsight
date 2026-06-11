#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	bool d = 1;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0 && s[i] == 'L') {
			d = 0;
		}
		if (i % 2 == 1 && s[i] == 'R') {
			d = 0;
		}
	}
	if (d){
		cout << "Yes";
	}else {
		cout << "No";
	}
		
}

















