#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 2e5+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 18;
const int off = 1 << logo;
const int treesiz = off << 1;

string a;
int main() {
	cin >> a;
	
	int sol = 0;
	for (int i = 0; i < (a.size() + 1) / 2; i++) {
		if (a[i] != a[a.size() - 1 - i]) sol++;
	}
	cout << sol;
	return 0;
}
