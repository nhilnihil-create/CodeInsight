#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e5 + 100;
double n;
int main() {
	
	cin >> n;
	int x = ceil(n / 1.08);
	int tmp = x * 1.08;
	if(tmp != n) {
		puts(":(");
	}else {
		cout << x << endl;
	}
	return 0;
} 