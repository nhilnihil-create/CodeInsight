#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005
char buf[SIZE];
int near_L[SIZE],near_R[SIZE];
int ans[SIZE];


int main(){

	scanf("%s",buf);
	int len;
	for(len = 0; buf[len] != '\0'; len++);

	for(int i = 0; i < len; i++){
		if(buf[i] == 'R'){

			near_R[i] = i;

		}else{

			near_R[i] = near_R[i-1];
		}
	}

	for(int i = len-1; i >= 0; i--){
		if(buf[i] == 'L'){

			near_L[i] = i;

		}else{

			near_L[i] = near_L[i+1];
		}
	}

	for(int i = 0; i < len; i++){

		ans[i] = 0;
	}

	for(int i = 0; i < len; i++){
		if(buf[i] == 'R'){

			if((near_L[i]-i)%2 == 0){

				ans[near_L[i]]++;

			}else{

				ans[near_L[i]-1]++;
			}

		}else{ //buf[i] == 'L'

			if((i-near_R[i])%2 == 0){

				ans[near_R[i]]++;
			}else{

				ans[near_R[i]+1]++;
			}
		}
	}

	printf("%d",ans[0]);
	for(int i = 1; i < len; i++){

		printf(" %d",ans[i]);
	}
	printf("\n");

	return 0;
}
