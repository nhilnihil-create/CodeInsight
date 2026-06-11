#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<deque>


#define REP(i,a,b) for(int i = (a); i < b; ++i)
#define inf 1e9+10
#define MOD 1000000007

using ll = long long;
using namespace std;

int main() {
	string s, t;

	cin >> s;
	cin >> t;

	int sum = 0;

	REP(i, 0, s.size()) {
		if (s[i] != t[i]) {
			++sum;
		}
	}

	cout << sum;

	return 0;
}