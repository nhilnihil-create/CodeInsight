#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 50;
long long h, w;
 
int main() {
	cin >> h >> w;
	if(h==1 || w==1) {
		cout << 1 << endl;
	}else {
		long long tmp = h*w;
		cout << (tmp/2) + (tmp&1) << endl;
	}
	
	
	return 0;
} 
