#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)

bool f[31];

int main() {
	for_(i,0,30) {
		int a; cin >> a;
		f[a] = true;
	}
	for_(i,1,31) if (!f[i]) cout << i << endl;
	return 0;
}