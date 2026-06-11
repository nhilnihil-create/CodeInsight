#include <iostream>
#include <cstdio>
using namespace std;

string a, b;
int c;
int main() {
	cin >> a >> b;
	for(int i=0; a[i]; i++) {
		if(a[i] != b[i]) c++;
	}
	cout << c;
	return 0;
}
