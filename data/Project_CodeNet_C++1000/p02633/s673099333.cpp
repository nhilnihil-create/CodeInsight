#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int X;
	int n;
	int p;


	cin >> X;
	n=1;
	p=360;
	while (p>0) {
		p%=X;
		if (p>0) {
			p+=360;
          n++;
		}
	}
	cout << (n * 360) / X << endl;
	return 0;
}

