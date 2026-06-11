#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

ll N;
ll table[SIZE];



int main(){

	scanf("%lld",&N);

	ll sum = 0;

	for(int i = 0; i < N; i++){

		scanf("%lld",&table[i]);
		sum += table[i];
	}

	sum /= 2;

	ll minus = 0;

	for(int i = 1; i < N; i += 2){

		minus += table[i];
	}

	ll tmp = sum-minus;
	printf("%lld",2*tmp);

	ll pre = tmp;
	for(int i = 0; i < N-1; i++){

		tmp = table[i]-pre;
		printf(" %lld",2*tmp);
		pre = tmp;
	}
	printf("\n");

	return 0;
}
