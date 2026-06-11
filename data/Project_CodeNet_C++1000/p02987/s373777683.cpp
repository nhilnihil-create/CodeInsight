#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	string s;
	cin >> s;
	int cnt(0);
	rep(i, 4)rep(j, 4) {
		if (i == j)continue;
		if (s[i] == s[j]) {
			cnt++;
		}
	}
	cnt /= 2;
	if (cnt == 2) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}