#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<string>w = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x = 0;
	for (int i = 0; i < w.size(); i++)if (s == w.at(i))x = i;
	x = 0 - x + 7;
	cout << x << endl;
}