#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	int a=1,b=1+m,c=b+1,d=c+m-1;
	while (1) {
		if (a<b) printf("%d %d\n",a,b);
		if (c<d) printf("%d %d\n",c,d);
		++a,--b,++c,--d;
		if (a>=b&&c>=d) break;
	} 
	return 0;
}