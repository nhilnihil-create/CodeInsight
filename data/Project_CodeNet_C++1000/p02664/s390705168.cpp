#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int inf = LLONG_MAX/2;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for (char c:s){
		if (c != '?') cout << c;
		else cout << 'D';
	}
	return 0;
}