#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <bitset>
#include <memory>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;


int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<pair<string, int>> vp;
	for (int i = 0; i < n; i++) {
		string s;
		int t;
		cin >> s >> t;
		vp.push_back(make_pair(s, t));
	}
	string x;
	cin >> x;
	int res = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		res += flag * vp[i].second;
		if (x == vp[i].first) flag = 1;
	}
	cout << res << endl;
}







