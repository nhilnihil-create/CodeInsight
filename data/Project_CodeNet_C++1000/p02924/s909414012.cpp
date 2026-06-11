#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 210;
long long n; 
int main() {
	
	scanf("%lld", &n);
	cout << n*(n-1)/2 << endl;	
	return 0;
}