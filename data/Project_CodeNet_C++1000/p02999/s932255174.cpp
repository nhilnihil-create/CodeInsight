#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int X, A;
	cin >> X >> A;
	int ans = 10;
	if (X < A){
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
