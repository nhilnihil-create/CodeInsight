#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N;
int W[105];

int main(){

	scanf("%d",&N);

	int sum = 0;
	for(int i = 0; i < N; i++){

		scanf("%d",&W[i]);
		sum += W[i];
	}

	int ans = BIG_NUM;
	int work = 0;

	for(int i = 0; i < N; i++){

		work += W[i];
		ans = min(ans,abs(work-(sum-work)));
	}

	printf("%d\n",ans);

	return 0;
}
