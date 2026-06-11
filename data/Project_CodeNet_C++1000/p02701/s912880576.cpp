#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e9;
int main() {
	int n; cin >> n;
	map<string, int> mg;
	int ans = 0;
	rep(i, n) {
		string s; cin >> s;
		mg[s]++;
		if (mg[s] == 1)
			ans++;
	}
	cout << ans;
}
