#include <iostream>
#include <cstdio>
using namespace std;

long long h, w;
int main() {
	cin >> h >> w;
	if(h>1 && w>1) cout << (h*w+1) / 2;
	else cout << 1;
	return 0;
}
