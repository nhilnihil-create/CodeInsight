#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
//using mint = modint;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	string t;
	cin >> t;
	for (int i = 0; i < (int)t.size(); i++) {
		if (t[i] == '?') t[i] = 'D';
	}
	cout << t << endl;
}
