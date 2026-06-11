#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BAGGAGE_MAX_NUM 100000
#define BAGGAGE_MAX_WEIGHT 10000
typedef long long llong;
int n, k;
llong BagWList[BAGGAGE_MAX_NUM];


int pSizeCheck(llong p){
	int countBag = 0;
	for (int i=0;i<k;i++){
		llong MtBag = 0;
		while(MtBag + BagWList[countBag] <= p){
			MtBag += BagWList[countBag];
			countBag++;
			if(countBag == n){
				return n; //領域外を見ないように．
			}
		}
	}
	return countBag;
}

int pSearch(){
	llong left = 0;
	llong right = BAGGAGE_MAX_NUM * BAGGAGE_MAX_WEIGHT;
	llong mid;
	while(left+1<right){
		mid = (left+right)/2;
		int check = pSizeCheck(mid);
		//nかそれより小さい値しか返ってこないため
		if(check == n){
			right = mid;
		}else{
			left = mid;
		}
	}
	return right;
}

int main(){
	scanf("%d%d",&n, &k);
	for(int i=0;i<n;i++){
		scanf("%llu",&BagWList[i]);
	}
	
	llong pResult = pSearch();
	printf("%llu\n",pResult);
	
	
	return 0;
}
