#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
long long n, k;

int main() {
	
	cin >> n >> k;
	
	n = n % k;
	
	cout << min(n, k - n) << endl;
	
	return 0;	
} 