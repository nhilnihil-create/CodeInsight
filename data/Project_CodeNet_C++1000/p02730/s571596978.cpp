#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	string s;
	cin >> s;

	bool strong = true;
	int len = s.length();

	string ss = s;
	reverse(ss.begin(), ss.end());
	if (s != ss) strong = false;

	string ls = s.substr(0, (len - 1) / 2);
	string rls = ls;
	reverse(rls.begin(),rls.end());
	if (ls != rls) strong = false;

	string rs = s.substr((len + 3)/2 -1 , (len - 1) / 2);
	string rrs = rs;
	reverse(rrs.begin(), rrs.end());
	if (rs != rrs) strong = false;

	if (strong) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return 0;
}