#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vi w;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool on = false;
	for(int i=0;i<n;i++) {
		int val = s[i]-'1';
		w.push_back(val);
		on = on || (val == 1);
	}
	int cho = n-1;
	int res = 0;
	if(on) {
		for(int i=0;i<n;i++) {
			if((w[i] == 1) && ((i & cho) == i)) {
				res ^= 1;
			}
		}
	} else {
		for(int i=0;i<n;i++) {
			if((w[i] == 2) && ((i & cho) == i)) {
				res ^= 2;
			}
		}
	}
	cout << res << '\n';
}
