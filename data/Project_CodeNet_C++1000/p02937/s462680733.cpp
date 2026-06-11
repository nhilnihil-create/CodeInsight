#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	string s, t;

	cin >> s >> t;
	vector<vector<int>> alp(26);
	for (int i = 0; i < s.size(); i++) {
		alp[s[i] - 'a'].push_back(i + 1);
	}

	ll now = 0;
	ll con = 0;
	bool flag = true;
	for (int i = 0; i < t.size(); i++) {
		if (alp[t[i] - 'a'].empty()) {
			flag = false;
			break;;
		}

		auto id = upper_bound(alp[t[i] - 'a'].begin(), alp[t[i] - 'a'].end(), now);
		if (id == alp[t[i] - 'a'].end()) {
			con++;
			now = alp[t[i] - 'a'][0];
		}
		else{
			now = *id;
		}
	}

	if (flag) {
		cout << con * (ll)s.size() + now << endl;
	}
	else
		cout << -1 << endl;

}