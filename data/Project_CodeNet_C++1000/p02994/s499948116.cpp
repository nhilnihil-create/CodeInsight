#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int N,L;

	scanf("%d %d",&N,&L);

	int base = 0;
	for(int i = 1; i <= N; i++){

		base += L+(i-1);
	}

	int minimum = BIG_NUM;
	int ans = -1;

	for(int i = 1; i <= N; i++){

		int tmp = 0;
		for(int k = 1; k <= N; k++){
			if(k == i)continue;

			tmp += L+(k-1);
		}
		if(abs(base-tmp) < minimum){
			minimum = abs(base-tmp);
			ans = tmp;
		}
	}

	printf("%d\n",ans);

	return 0;
}
