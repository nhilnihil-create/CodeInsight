#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")




int main() {
	string s;
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	if (t[0] != 's') {
		s.push_back('s');
	}
	else {
		s.push_back('e');
		s.push_back('s');
	}
	cout << s << endl;
	return 0;
}