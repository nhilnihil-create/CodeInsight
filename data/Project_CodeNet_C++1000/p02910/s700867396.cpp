#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cassert>

using namespace std;
using ll = long long;

#define nl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define trav(x) for(auto& i: x)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	bool ans = true;
	for(int i = 0; i < s.size(); i++) {
		if((i + 1) & 1) {
			if(s[i] == 'L') {
				ans = false;
				break;
			}
		} else {
			if(s[i] == 'R') {
				ans = false;
				break;
			}
		}
	}
	if(ans) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}