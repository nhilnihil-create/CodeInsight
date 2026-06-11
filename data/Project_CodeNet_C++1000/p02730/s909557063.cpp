#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool p(string& s) {
	bool y = 1;
	for (int i=0; i<=(int)s.size()/2; i++) y&=s[i]==s[(int)s.size()-i-1];
	return y;
}
int main() {
	string s;
	cin >> s;
	int n = s.size();
	bool y = 1;
	y &= p(s);
	string l = s.substr(0,n/2);
	y &= p(l);
	// cout << l << '\n';
	s.erase(s.begin(),s.begin()+n/2+1);
	// cout << s << '\n';
	y &= p(s);
	cout << (y ? "Yes" : "No");
	return 0;
}
