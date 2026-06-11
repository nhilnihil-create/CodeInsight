#include <iostream>
#include <cstdio>
using namespace std;
 
int k, x;
int main() {
	cin >> k >> x;
	cout << (k*500>=x ? "Yes" : "No");
	return 0;
}