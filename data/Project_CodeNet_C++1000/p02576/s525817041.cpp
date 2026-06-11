#include <bits/stdc++.h>
using namespace std;
signed main(void){
	int n,x,t;
	scanf("%d%d%d",&n,&x,&t);
	if(n%x==0) printf("%d",n/x*t);
	else printf("%d",(n/x+1)*t);
	return 0;
} 