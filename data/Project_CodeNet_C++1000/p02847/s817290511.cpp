#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	map<string, int> W;
	W["SUN"] = 7;
	W["MON"] = 6;
	W["TUE"] = 5;
	W["WED"] = 4;
	W["THU"] = 3;
	W["FRI"] = 2;
	W["SAT"] = 1;
	string s; cin >> s;
	cout << W[s] << endl;
	return 0;
}