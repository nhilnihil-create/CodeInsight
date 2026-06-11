#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005

int N;
int A[SIZE];
int table[SIZE];


int main(){

	scanf("%d",&N);
	for(int i = 1; i <= N; i++){

		scanf("%d",&A[i]);
	}
	for(int i = 1; i <= N; i++){

		table[i] = 0;
	}

	int num = 0;
	stack<int> S;

	for(int i = N; i >= 1; i--){

		int sum = 0;
		for(int k = 2*i; k <= N; k += i){

			sum += table[k];
		}
		if(sum%2 == A[i]){

			//Do noghint
		}else{
			num++;
			table[i] = 1;
			S.push(i);
		}
	}

	printf("%d\n",num);

	if(num == 0){
		return 0;
	}

	printf("%d",S.top());
	S.pop();

	while(!S.empty()){

		printf(" %d",S.top());
		S.pop();
	}
	printf("\n");

	return 0;
}
