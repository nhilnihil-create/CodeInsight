#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,j=m+1;i<j;i++,j--)
		printf("%d %d\n",i,j);
	for(int i=m+2,j=2*m+1;i<j;i++,j--)
		printf("%d %d\n",i,j);
}