#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main () {
	cin >> a >> b >> c;
	if (b+c >= a) {
		cout << c-a+b << endl; 
	} else if ((b+c < a)&&(b < c)) {
		cout << 0 << endl;
	} else {
		cout << 0 << endl;
	}
}