#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main(){

	int N,D;
	scanf("%d %d",&N,&D);

	bool check[25];
	for(int i = 0; i < N; i++){

		check[i] = false;
	}

	int ans = 0;

	for(int i = 0; i < N; i++){
		if(check[i])continue;

		ans++;

		for(int k = 0; k <= 2*D && i+k < N; k++){

			check[i+k] = true;
		}
	}

	printf("%d\n",ans);


	return 0;
}
