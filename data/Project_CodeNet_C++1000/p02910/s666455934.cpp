#include<stdio.h>
#include <iomanip>
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include <random>
#include <chrono>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int main() {
	string s,ans="Yes";
	cin >> s;
	rep(i, s.size()) {
		if (s.at(i) == 'U' || s.at(i) == 'D') {
			continue;
		}
		if (i % 2 == 0) {
			if (s.at(i) == 'L') {
				ans = "No";
			}
		}
		else {
			if (s.at(i) == 'R') {
				ans = "No";
			}

		}
	}

	cout << ans;

}