#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt=0;
vector<int> G;

void insertsort(int A[],int n,int g){
	for(int i = g; i<n;i++){
		int temp=A[i],j=i-g;
		while(j>=0&&A[j]>temp){
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
		A[j+g]=temp;
	}
	return ;
}

void shellsort(int A[],int n){
	//generate the G array
	for (int h =1;;){
		if (h>n) break;
		G.push_back(h);
		h=3*h+1;
	}
	
	for(int i=G.size()-1;i>=0;i--)	insertsort(A,n,G[i]);
	
	return ;
}

int main (){
	int n ,A[1000010];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	
	shellsort(A,n);

	cout<<G.size()<<endl;
	for(int i =G.size()-1;i>=0;i--){
		printf("%d",G[i]);
		if(i) printf(" ");
	}
	printf("\n%d\n",cnt);
	for(int i =0;i<n;i++) printf("%d\n", A[i]);
	return 0;
}
