#include <iostream>
#include <cstdio>
using namespace std;

int n;
int main() {
	cin >> n;
	int i, j, x, y, z;
	for(i=1; i<n; i++, puts("")) {
		for(j=i+1; j<=n; j++) {
			x=i, y=j, z=1;
			while((x&1) == (y&1)) x>>=1, y>>=1, z++;
			printf("%d ", z);
		}
	}
	return 0;
}