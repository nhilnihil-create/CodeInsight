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
	int n, m;
	map<int, int> mp;
	string s;
	int countac = 0, countwa = 0;
	cin >> n >> m;
	rep(i, m) {
		cin >> n >> s;
		if (s == "AC"&&mp[n]!=-1) {
			countac++;
			countwa += mp[n];
			mp[n] = -1;
		}
		else if (s == "WA" && mp[n] != -1) {
			mp[n]++;
		}
	}

	cout << countac << " " << countwa;
}