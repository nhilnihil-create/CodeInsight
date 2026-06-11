#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	
	int x = (n-1)/1000+1;
	x*=1000;
	printf("%d\n", x-n);
	
	return 0;
}