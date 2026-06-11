#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];

	int sum;
	int mini = 1e9;
	rep(i, 101) {
		sum = 0;
		rep(j, n) {
			sum += (x[j] - i) * (x[j] - i);
		}
		mini = min(sum, mini);
	}

	cout << mini << endl;





	return 0;
}
