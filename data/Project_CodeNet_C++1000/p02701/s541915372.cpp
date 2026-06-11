#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
string c;
signed main() {
	cin >> n;
	set <string> s;
	for(int i = 0;i<n;i++){
		cin >> c;
		s.insert(c);
	}cout << s.size() << endl;
	return 0;
}