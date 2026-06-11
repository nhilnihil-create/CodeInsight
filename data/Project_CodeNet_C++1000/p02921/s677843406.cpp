#include <iostream>
#include <cstdio>
using namespace std;

string a, b;
int ans;
int main() {
	cin >> a >> b;
	for(int i=0; i<3; i++) ans += (a[i]==b[i]);
	cout << ans;
	return 0;
}