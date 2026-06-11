#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N,K;
char buf[SIZE];

int main(){

	scanf("%d %d",&N,&K);
	scanf("%s",buf);

	int ans = 0;
	int RL = 0,LR = 0;

	for(int i = 0; i < N; i++){
		if(buf[i] == 'L'){
			if(i == N-1)continue;

			if(buf[i+1] == 'L'){

				ans++;
			}else{

				LR++;
			}

		}else{

			if(i == N-1)continue;

			if(buf[i+1] == 'R'){

				ans++;

			}else{

				RL++;
			}
		}
	}

	ll num = min(LR,RL);

	if(num <= K){ //ペアを全消化できる場合

		ans += 2*num;
		K -= num;

		int rest=LR+RL-2*num; //どちらか多い方が残っている場合あり

		ans += min(K,rest);

	}else{ //ペア消化でKが尽きる場合

		ans += 2*K;
	}

	printf("%d\n",ans);

	return 0;
}
