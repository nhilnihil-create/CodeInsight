#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#define MAX_m 100
using namespace std;

int main(){
	int A[1000001];//問題文の要求通りの要素数に設定するとオーバーフローする
	int num;//入力数

	//配列を0で初期化
	for(int i=0;i<1000001;i++){
		A[i] = 0;
	}

	cin >>num;
	for(int i=0;i<num;i++){
		scanf("%d",&A[i]);
	}

	void shellSort(int A[],int N);
	shellSort(A,num);	

	return 0;
}

//0?g-1までの余りで分類したg個の数列を別々にソートする
/*----通常のinsertionSortの1がgになっただけ--------*/
int insertionSort(int A[],int N,int g){
	int tmp;
	int j;
	int cnt=0;//要素の移動回数
	for(int i=g;i<N;i++){
		tmp = A[i];
		j = i -g;
		while(j >= 0 && A[j] > tmp){
			A[j+g] = A[j];
			j = j-g;
			cnt++;
		}
		A[j+g] = tmp;
	}
	return cnt;
}
/*-----------------------------------------------*/

void shellSort(int A[],int N){
	int cnt = 0;
	int int_LogN =(int)(log((double)N)/log(2.0));
	int m = (int)pow((double)2,(double)int_LogN);
	int tmp_m;
	int G[MAX_m + 1];
	int ttlcnt = 0;//total count

	cout <<int_LogN+1 <<endl;


	tmp_m = m;
	//まとめる
	for(int i=0;i<int_LogN+1;i++){//int_logN==2→2^2,2^1,2^0と変化
		G[i] = tmp_m;
		tmp_m = tmp_m / 2;
		cout <<G[i] <<" ";
	}
	cout <<endl;



	for(int i=0;i<int_LogN+1;i++){
		ttlcnt += insertionSort(A,N,G[i]);
	}

	cout <<ttlcnt <<endl;

	for(int i=0;i<N;i++){
		cout <<A[i] <<endl;
	}
	
}