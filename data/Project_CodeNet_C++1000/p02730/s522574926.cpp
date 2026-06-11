#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF (1e9)
#define PI (acos(-1))

bool ReverseCheck(string str) {
	bool flg = false;
	string rev = str;
	reverse(rev.begin(), rev.end());
	if (rev == str) flg = true;
	return flg;
}

int main() {
	string s, front, back, ans = "No";
	cin >> s;

	if (ReverseCheck(s)) {
		front = s.substr(0, s.size()/2);
		back = s.substr((s.size()+1)/2, s.size()/2);
		if (ReverseCheck(front) && ReverseCheck(back)) ans = "Yes";
	}

	cout << ans;
	return 0;
}