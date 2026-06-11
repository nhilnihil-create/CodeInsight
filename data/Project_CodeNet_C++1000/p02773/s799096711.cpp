#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <map>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	map<string, int> dic;
	string str;
	int n;
	cin >> n;
	int ans=0;
	rep(i, n) {
		cin >> str;
		dic[str]++;
		ans = max(ans,dic[str]);
	}

	for (auto e : dic) {
		if (e.second == ans)
			cout << e.first<<endl;
	}
}