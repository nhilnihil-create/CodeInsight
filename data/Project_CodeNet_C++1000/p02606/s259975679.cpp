#include<bits/stdc++.h>
using namespace std;

int main() {
	int l,r,d; cin >> l >> r >> d;
	
	int l1,r1;
	l1 = l/d - (l%d==0);
	r1 = r/d - (d%d==0);
	
	cout << r1 - l1 + 1 << endl;
}