/*
123 321
ABCDEFG
GABCDEF
FGABCDE
EFGABCD
DEFGABC
CDEFGAB
BCDEFGA
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int l = i, r = n+1-i;
		if(n%2==0 && r-l <= l+n-r) r--;
		printf("%d %d\n", l, r);
		//printf("%d %d %d %d\n", l, r, r-l, l+n-r);
	}
	
	return 0;
}