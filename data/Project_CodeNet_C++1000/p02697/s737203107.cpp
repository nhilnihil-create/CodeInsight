#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	int i;
	scanf("%d%d",&n,&m);
	if (n%2==1) {
		for (i=1;i<=m;i++)
			printf("%d %d\n",i,n+1-i);
		}
	else {
		for (i=1;i<=m;i++)
			if (i<=(n-2)/2/2)
				printf("%d %d\n",i,n-i);
			else printf("%d %d\n",i,n-1-i);
	}
	return 0; 
}