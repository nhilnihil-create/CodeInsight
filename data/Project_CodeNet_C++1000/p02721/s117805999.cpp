#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005

int N,K,C;
int L[SIZE],R[SIZE];
char buf[SIZE];


int main(){

	scanf("%d %d %d",&N,&K,&C);
	scanf("%s",buf);

	int index_L = 0;
	int skip = 0;

	for(int i = 0; buf[i] != '\0'; i++){
		if(buf[i] == 'o' && skip == 0){

			L[index_L++] = i;
			skip = C;
		}else{
			if(skip > 0){

				skip--;
			}
		}
	}

	if(index_L > K){

		return 0;
	}

	int index_R = index_L-1;
	skip = 0;
	for(int i = N-1; i >= 0; i--){
		if(buf[i] == 'o' && skip == 0){

			R[index_R--] = i;
			skip = C;
		}else{
			if(skip > 0){

				skip--;
			}
		}
	}

	for(int i = 0; i < index_L; i++){
		if(L[i] == R[i]){

			printf("%d\n",L[i]+1);
		}
	}

	return 0;
}
