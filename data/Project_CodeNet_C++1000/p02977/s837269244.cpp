#include<cstdio>
int n;
int main(){
	scanf("%d",&n);
	if((n&(-n))==n)return puts("No"),0;
	puts("Yes");
	puts("1 2");
	puts("2 3");
	printf("%d %d\n",3,1+n);
	printf("%d %d\n",1+n,2+n);
	printf("%d %d\n",2+n,3+n);
	for(int i=4;i<n;i+=2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i,i,i+1,1,n+i+1,n+i+1,n+i);
	if(n%2==1)return 0;
	int x=n+1;
	for(int i=1;i<=100;i++){
		if(x&(1<<i)){
			int X=1<<i,Y=x-X;
			printf("%d %d\n",X,n);
			printf("%d %d\n",Y+n,2*n);
			break;
		}
	}
}