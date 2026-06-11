#include<cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int z=1;
	while(z*2<=n)z*=2;
	if(n==z){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=2;i<n;i+=2){
		printf("%d %d\n",1,i);
		printf("%d %d\n",i,i+1+n);
		printf("%d %d\n",1,i+1);
		printf("%d %d\n",i+1,i+n);
	}
	printf("%d %d\n",n+1,2+n);
	if(n%2==0){
		printf("%d %d\n",z+1,n);
		printf("%d %d\n",n-z,2*n);
	}
}