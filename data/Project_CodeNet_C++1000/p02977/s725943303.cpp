#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,m,k,tp,ls;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i<<=1)
	if(i==n)return puts("No"),0;
	puts("Yes");
	if(n==6)m=n-1,printf("6 5\n12 2\n");
	else if(n&1)m=n;
	else m=n-5,tp=n-1^n,
	printf("%d %d\n%d %d\n",n,n-1,2*n,tp);
	k=m;
	if((m&3)==1)k-=2;
	for(int i=1;i<=k;i++){
		if(ls)printf("%d %d\n",ls,i);
		if(i==tp){
			for(int j=n-1;j>n-4;j--)
			printf("%d %d\n%d %d\n",j,j-1,j+n,j+n-1);
			printf("%d %d\n%d %d\n",2*n-1,n-4,i,n-1);
			ls=2*n-4;
		}
		else ls=i;
	}
	for(int i=1;i<=k;i++)
	printf("%d %d\n",ls,i+n),ls=i+n;
	if(k<m)printf("%d %d\n%d 1\n1 %d\n%d %d\n",
	k+1,k+2,k+2,n+k+1,n+k+1,n+k+2);
}