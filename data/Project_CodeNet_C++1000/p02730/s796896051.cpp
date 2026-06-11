#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cstr(str);
	
	rep(i, str.length() / 2) {
		if (str[i] != str[(str.length() -1)/ 2  - i-1]) {
			cout << "No" << endl;
			return 0;
		}
		if (str[i + (str.length() + 3) / 2 -1] != str[str.length() - 1 - i]) {
			cout << "No" << endl;
			return 0;
		}
		if (str[i] != str[str.length() - i - 1]) {
			cout << "No" << endl;
			return 0;
		}
			
	}
	cout << "Yes" << endl;
	
	

	return 0;
}
