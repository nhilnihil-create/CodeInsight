#include <bits/stdc++.h>
using namespace std;

int main(){

	int p, q, r;
	cin >> p >> q >> r;
	cout << p +q + r - max(max(p,q), max(p,r));
	return 0;
}