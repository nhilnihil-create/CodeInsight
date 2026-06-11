#include<iostream>
#include<cstdio>

using namespace std;

int A[1000000],cnt;

void insertionsort(int *A,int n,int g){
	int j,v;
	for(int i=g;i<n;i++){
		v=A[i];
		j=i-g;
		while(j>=0&&A[j]>v){
			A[j+g]=A[j];
			j=j-g;
			cnt++;
		}
		A[j+g]=v;
	}
}

void shellsort(int *A, int n){
	int G[100],m,temp=0,i=1;
	m = 1;
	G[0]=1;
	while(1){
		temp=3*G[i-1]+1;
		if(temp>n)
		break;
		G[i]=temp;
		i++;
		m++;
	}
	printf("%d\n",m);
	for(i=m-1;i>0;i--){
		printf("%d ",G[i]);
	}
	printf("%d\n",G[0]);
	for(i=m-1;i>=0;i--){
		insertionsort(A,n,G[i]);
	}
	printf("%d\n",cnt);
	for(i=0;i<n;i++){
		printf("%d\n",A[i]);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	shellsort(A,n);
}