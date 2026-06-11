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
	string s, t;
	int ans = 0;
	cin >> s >> t;
	rep(i, s.size()) {
		if (s.at(i) == t.at(i)) {
			ans++;
		}
	}
	cout << ans;
}