#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
	int n,q,c=0;
	int S[100000];
	int T[100000];
	cin >> n;
	rep(i, n) cin >> S[i];
	cin >> q;
	rep(i, q) cin >> T[i];
	rep(i, q) {
		rep(j, n) {
			if (S[j] == T[i]) {
				c++;
				break;
			}
		}
	}
	cout << c << endl;
	return 0;
}