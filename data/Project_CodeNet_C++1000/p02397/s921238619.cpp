#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	for (a=0; a<10000; a++ ){
		cin >> b >> c;
		if ( b == 0&&c == 0) break;
		else {
			if ( b<=c ){cout<< b << " " << c << endl;}
			else {
				cout<< c << " " << b << endl;
				}
			}
	}
	return 0;
}

