#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll sum = 0;
	string s;
	cin >> s;
	vector<int> v(s.length()+2);
	for (int i = 0; i < s.length() ; i++) {
		if (s.substr(i, 1) == "<") {
			v[i+1]=max(v[i+1],v[i]+1);
		}
	}
	for (int i = s.length(); i >=0 ; i--) {
		if (s.substr(i, 1) == ">") {
			v[i]=max(v[i],v[i+1]+1);
		}
	}
	for (int i = 0; i < s.length()+1; i++) {
		sum+=v[i];
	}
	cout << sum << endl;
	return 0;
}
