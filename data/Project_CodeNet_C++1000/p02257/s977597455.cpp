#include<stdio.h>
#include<math.h>
int PN(int x);
int main(){
	int i,n,x;
	int count=0,ncount=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(PN(x)== 0){
			count++;
		}
	}
	printf("%d\n",count);
}

int PN(int x){
	int i;
	if(x == 2){
		return 0;
	}else if(x<2 || x%2==0){
		return -1;
	}
	i = 3;
	while(i <= sqrt(x)){
		if(x%i==0){
			return -1;
		}
		i = i+2;
	}
	return 0;
}