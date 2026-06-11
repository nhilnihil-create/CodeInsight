#include <iostream>
#include <cstdio>
using namespace std;
 
int x;
int main() {
	cin >> x;
	puts(x>=2000 || x%100 <= x/100*5 ? "1" : "0");
	return 0;
}