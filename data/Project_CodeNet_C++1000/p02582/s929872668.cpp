#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>
#include <tuple>
#include <map> 
#include <set>
#include <stack>
#include <functional>
#define ll long long
using namespace std;

int main() {
	string s;
	cin >> s;
	int rCnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R') rCnt++;
	}

	if (rCnt == 1) {
		cout << rCnt << endl;
		return 0;
	}
    if (rCnt == 2 && s[1] == 'R') {
		cout << rCnt << endl;
		return 0;
	}
	else if(rCnt==2) {
		cout << 1 << endl;
		return 0;
	}
	cout << rCnt << endl;
	return 0;
}