#include <stdio.h>

int liner(int A[],int b, int c){
	A[b]=c;
	int i=0;
	while(A[i] != c) i++;
	return i != b ;
}

int main(){
	int n,c,A[10000+1],b,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	scanf("%d",&b);
		for(int i=0;i<b;i++){
				scanf("%d",&c);

			if (liner(A,n,c)) sum +=1;
			}

	printf("%d\n",sum);

	return 0;
}