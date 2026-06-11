#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int H,W,A,B;
	cin >> H >> W >> A >> B;

	if(A*2<W && B*2<H) {
		rep(i,H) {
			rep(j,W)
				if(i<B&&j<A || i>=B&&j>=A)
					cout << 1;
				else
					cout << 0;
			cout << endl;
		}
	} else
		cout << "No" << endl;
}