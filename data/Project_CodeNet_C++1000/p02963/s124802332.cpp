#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pii;


int main() {
	lld S;
	cin >> S;
    const lld LIMIT = 1e9;
	if (S <= LIMIT) {
	  cout << "0 0 " << S << " 0 0 1\n";
	} else {
	  cout << "0 0 " << LIMIT << " 1 ";
	  lld x = (S + LIMIT - 1ll) / LIMIT;
	  lld y = x * LIMIT - S;
	  cout << y << " " << x << "\n";
	}
	return 0;
}