#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	string s;
	cin >> s;
	int n = s.size();

	for(int i = 0;i < n;i++){
		if(s[i] == '?') s[i] = 'D';
	}

	cout << s << endl;

	return 0;
}
