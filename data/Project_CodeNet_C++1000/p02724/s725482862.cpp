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

	cint(x);
	int cnt = 0;
	
	cnt = x / 500;
	x -= cnt * 500;
	cnt *= 1000;
	cnt += x - (x%5);
	cout << cnt << endl;


	return 0;
}
