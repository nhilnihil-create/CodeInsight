#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[3][3];
	bool f[3][3] = {};

	rep(i, 3)rep(j, 3) cin >> a[i][j];

	int n; cin >> n;
	int b;
	while (n--) {
		cin >> b;
		rep(i, 3)rep(j, 3) if (a[i][j] == b) f[i][j] = true;
	}

	if (f[0][0] && f[0][1] && f[0][2]) { cout << "Yes" << endl; return 0; }
	if (f[1][0] && f[1][1] && f[1][2]) { cout << "Yes" << endl; return 0; }
	if (f[2][0] && f[2][1] && f[2][2]) { cout << "Yes" << endl; return 0; }
	if (f[0][0] && f[1][0] && f[2][0]) { cout << "Yes" << endl; return 0; }
	if (f[0][1] && f[1][1] && f[2][1]) { cout << "Yes" << endl; return 0; }
	if (f[0][2] && f[1][2] && f[2][2]) { cout << "Yes" << endl; return 0; }
	if (f[0][0] && f[1][1] && f[2][2]) { cout << "Yes" << endl; return 0; }
	if (f[0][2] && f[1][1] && f[2][0]) { cout << "Yes" << endl; return 0; }

	cout << "No" << endl;



	return 0;
}
