#include<cstdio>
using namespace std;
int n,m;
int main(){
	scanf("%d",&n);
	m=n;while(!(m&1)) m>>=1;
	if(m==1){puts("No");return 0;}
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for (int i=4;i<n;i+=2)
	printf("1 %d\n%d %d\n1 %d\n%d %d\n",i,i,i+1,n+i+1,n+i+1,n+i);
	if(!(n&1)) printf("%d %d\n%d %d\n",n,n+n-1,n<<1,n^n-1^1);
	return 0;
}