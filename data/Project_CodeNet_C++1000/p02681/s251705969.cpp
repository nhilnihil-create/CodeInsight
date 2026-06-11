#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <cmath>
#define ll long long

using namespace std;

const double pi = 3.14159265358979323846;

vector<int> g[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;

	cin >> s >> t;

	if (t.substr(0, t.size() - 1) == s) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}



	return 0;
}