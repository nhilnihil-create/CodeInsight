#include <iostream>
#include <cstdio>
using namespace std;
 
int n;
double x;
int main() {
	cin >> n;
	x = n / 1.08;
	for(int i=x; i<x+5; i++) {
		if(int(i*1.08) == n) {cout << i << endl; return 0;}
	}
	puts(":(");
	return 0;
}