#include <iostream>
#include <cstdio>
using namespace std;

int n, k, s;
int main() {
	int i;
	cin >> n >> k >> s;
	for(i=0; i<k; i++) printf("%d ", s);
	for(; i<n; i++) printf("%d ", s<1e9 ? s+1 : 1);
	return 0;
}