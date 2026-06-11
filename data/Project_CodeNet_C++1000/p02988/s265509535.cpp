#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
int P[25];

int main(){

	scanf("%d",&N);

	for(int i = 0; i < N; i++){

		scanf("%d",&P[i]);
	}

	int ans = 0;
	for(int i = 1; i < N-1; i++){
		if(P[i] > P[i-1] && P[i] < P[i+1]){

			ans++;

		}else if(P[i] < P[i-1] && P[i] > P[i+1]){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
