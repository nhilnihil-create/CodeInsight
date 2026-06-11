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
	int a, b;
	cin >> a >> b;
	int n = 10;
	int aa, bb;
	while (true){
		aa = (n * 8) / 100;
		bb = n / 10;
		if (aa == a && bb == b) {
			cout << n << endl;
			return 0;
		}
		if (aa > a || bb > b) {
			cout << -1 << endl;
			return 0;
		}
		n++;
	}

	return 0;
}
