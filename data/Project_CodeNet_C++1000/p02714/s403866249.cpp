#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;

	map<char, ll> mp;
	rep(i, n) {
		if (s[i]=='R') mp['R']++;
		if (s[i]=='G') mp['G']++;
		if (s[i]=='B') mp['B']++;
	}

	ll res = mp['R'] * mp['G'] * mp['B'];
	for (ll i=0; i<(ll)s.size(); i++) {
		for (ll j=i+1; j<(ll)s.size(); j++) {
			ll k = 2*j - i;
			if (s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i] && k<n) res--;
		}
	}
	cout << res << endl;
}