#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define Max 1000000

int64_t cnt = 0;

void insertionSort(int *A,int n, int g){
	int v=0,j=0;
	//?????????g????£???§?????\?????????????????£?????????
	for(int i = g;i < n;++i){
		v = A[i];
		j = i-g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g] = v;
	}
}

std::vector<int> G;

void  shellSort(int A[],int n){
	//g(n+1) =3g(n) + 1????????????????????????
	for(int i=1; ; ){
		if(i > n)
			break;
		G.push_back(i);
		i = 3*i + 1;
	}


	for(int i=G.size() - 1; i >= 0;i--){
		insertionSort(A,n,G[i]);
	}
}


int main(){
	int n=0;
	int A[1000000];

	std::cin>>n;
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	
	shellSort(A,n);
	
	std::cout<<G.size()<<std::endl;
	for(int i=G.size() - 1; i >= 0;i--){
		if(i == G.size() -1){
			std::cout<<G[i];
			continue;
		}
		std::cout<<" " <<G[i];
	}
	std::cout<<std::endl;
	
	std::cout<<cnt<<std::endl;

	for(int i=0;i<n;i++){
		std::cout<<A[i]<<std::endl;
	}

	return 0;
}