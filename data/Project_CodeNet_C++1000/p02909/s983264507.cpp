#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s, c, r;
	s = "Sunny";
	c = "Cloudy";
	r = "Rainy";
	string i, o;
	cin >> i;
	if (i==s) o = c;
	else if (i==c) o = r;
	else o = s;
	cout << o << endl;
	return 0;
}