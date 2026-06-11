#include<stdio.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define BUF_SIZE 1024

int count = 0;

void insertionSort(int array[],int n,int g){
	int v,j;
	for(int i = g;i < n; i++){
		v = array[i];
		j = i - g;
		while(j >= 0 && array[j] > v){
			array[j+g] = array[j];	//??°??????????????§???????????????
			j = j - g;
			count++;
		}
		array[j+g] = v;
	}
}

void shellSort(int array[],int n){
	int m = 0;
	int s = 1;

	while((n/s) > 0){
		s *= 2;
		m++;	//2^(mult-1)?????§?????????????????¨???????¨?
	}

	int G[20];

	for(int k = 0,t = 1; k < m; k++){
		G[k] = n/t;
		t *= 2;
	}

	for(int i = 0; i < m;i++){
		insertionSort(array,n,G[i]);
	}

	printf("%d\n",m);
	for(int i = 0; i < m; i++){
		if(i != m-1){
			printf("%d ",G[i]);
		}else{
			printf("%d\n",G[i]);
		}
	}
	printf("%d\n",count);
	for(int i = 0; i < n; i++){
		printf("%d\n",array[i]);
	}

}

int main(int argc,char* argv[]){
	char buf[BUF_SIZE];
	int n = atoi(fgets(buf,BUF_SIZE,stdin));
	int array[1000000];

	for(int i = 0; i < n; i++){
		cin >> array[i];
	}

	shellSort(array,n);

}