#include <iostream>
#include <cstdio>
using namespace std;

long long n, a, m=1, e=1e18, fl;
int main() {
	cin >> n;
	while(n--) {
		cin >> a;
		if(a <= e/m) m *= a;
		else fl = 1;
		if(m==0) break;
	}
	if(m==0) cout << 0;
	else if(fl) cout << -1;
	else cout << m;
	return 0;
}
