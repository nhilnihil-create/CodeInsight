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

	int sum;
	int mx = -1;

	int k, n;
	cin >> k >> n;
	int in1, in2 = -1,in0;
	rep(i, n) {
		cin >> in1;
		if (in2 >= 0) {
			mx = max(mx, in1 - in2);
		}
		else in0 = in1;
		in2 = in1;
	}
	sum = k - max(mx, k - in1 + in0);
	cout << sum << endl;

	return 0;
}
