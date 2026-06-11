#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	vector<int> M(2), D(2);
	rep(i, 2) cin >> M[i] >> D[i];
	if (D[1] == 1) cout << 1 <<endl;
	else cout << 0 << endl;
	return 0;
}
