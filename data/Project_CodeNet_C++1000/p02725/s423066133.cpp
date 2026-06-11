#include <cstdio> 
#include <iostream>
#include<algorithm>
#include <cstring>

using namespace std;

const int maxn = 2*1000000;
int house[maxn];
int reladis[maxn];

int findm(int arr[],int n){
	int m = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > arr[m]){
			m = i;
		}
	}
	return m;
}

int main(){
	int K,N;
	int max;
	int mindis;
	scanf("%d%d",&K,&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&house[i]);
		if(i > 0){
			reladis[i] = house[i] - house[i-1];
		}
	}
	reladis[0] = K-house[N-1]+house[0];
	max = findm(reladis,N);
	if(max == 0){
		mindis = house[N-1] - house[0];
	}else{
		mindis = K-house[max]+house[max-1];
	}
	printf("%d",mindis);
}