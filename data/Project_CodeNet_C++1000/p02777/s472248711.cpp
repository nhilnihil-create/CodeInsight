#include<bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	string d, e, choose;
	cin >> d >> e >> a >> b >> choose;
	if(d == choose) {
		a--;
	} else {
		b--;
	}
	cout << a << " " << b << endl;
}