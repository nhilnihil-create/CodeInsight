#include<bits/stdc++.h>
using namespace std;

#define i64 long long int

bool chk(int a, int b, int c) {
	if(a>=c || b>=c) return false;
	
	// 2sqrt(a*b) ? c - a - b
	i64 rem = c - a - b;
	if(rem<0) return false;
	
	// l && rem^2
	i64 l = 4LL*a*b;
	
	return rem*rem>l;
}

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	puts(chk(a, b, c) ? "Yes" : "No");
	
	return 0;
}