#include<stdio.h>
int a[1000100],g[100000]={1},cnt=0,m=0;

void shell(int A[],int g,int n){
	for(int i=g;i<n;i++){
		int v=a[i];
		int j=i-g;
		while(j>=0&&A[j]>v){
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellSort(int A[],int n){
	while(3*g[m]+1<n){
		m++;
		g[m]=3*g[m-1]+1;
	}
	for(int i=m;i>=0;i--){
		shell(A,g[i],n);
	}
}
int main(){
	int i,n,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	shellSort(a,n);
	printf("%d\n",m+1);
	for(i=m;i>=0;i--){
		printf("%d",g[i]);
		if(i!=0) printf(" ");
		else printf("\n");
	}
	printf("%d\n",cnt);
	for(i=0;i<n;i++)	printf("%d\n",a[i]);
} 
