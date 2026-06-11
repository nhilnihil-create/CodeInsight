#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n;
int main() {
	scanf("%d",&n);
	if(n == (n&(-n)) ) {
		puts("No");
		return 0;
	}
	printf("Yes\n1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	if(n == 3) return 0;
	int cur=4;
	for(;cur<=n-1;cur+=2) 
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",cur,cur+1,cur+1,n+1,n+1,n+cur,n+cur,n+cur+1);
	if(cur == n+1) return 0;
	for(int i=2;i<=n;++i)
		if((n^i^1)<=n) {
			if(i&1) printf("%d %d\n%d %d\n",n,i,n+n,(n^i^1)+n);
			else printf("%d %d\n%d %d\n",n,i+n,n+n,(n^i^1));
			return 0;
		}
	return 0;
}