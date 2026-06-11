#include <bits/stdc++.h>
using namespace std;
void prt(int x,int y) {
	printf("%d %d\n",x,y);
}
int main() {
	int n,m=1;
	scanf("%d",&n);
	while(m<n) m<<=1;
	if(m==n) printf("No\n");
	else {
		printf("Yes\n");
		prt(1,2),prt(2,3),prt(3,n+1),prt(n+1,n+2),prt(n+2,n+3);
		for(int i=4;i<n;i+=2) {
			prt(1,i),prt(1,i+1);
			prt(i,i+1+n),prt(i+1,i+n);
		}
		if(n%2==0) {
			for(int i=2;i<n;i++) {
				if((n^i^1)<n) {
					prt(i,n);
					prt(n^i^1,2*n);
					break;
				}
			}
		}
	}
	return 0;
}