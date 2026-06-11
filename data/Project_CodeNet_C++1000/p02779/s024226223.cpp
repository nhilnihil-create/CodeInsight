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
	int N;
	map<string, bool> mp;
	string S;
	cin >> N;
	rep(i, N) {
		cin >> S;
		if (mp[S] == 1) {
			cout << "NO";
			return 0;
		}
		mp[S] = 1;
	}
	cout << "YES";
}