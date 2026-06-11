#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int N, K;
	scanf("%d %d\n", &N, &K);
	bool is_L[N + 2];
	is_L[0] = false;
	is_L[N + 1] = true;
	for (int i = 1; i <= N; ++i){
		char s;
		scanf("%c", &s);
		is_L[i] = s == 'L';
	}
	int happy = 0;
	for (int i = 1; i <= N; ++i){
		if(is_L[i - 1] && is_L[i]) happy++;
		else if(!is_L[i] && !is_L[i + 1]) happy++;
	}
	int lr = 0, rl = 0;
	for (int i = 2; i <= N; ++i){
		if(is_L[i - 1] && !is_L[i]) lr++;
		else if(!is_L[i - 1] && is_L[i]) rl++;
	}
	int psuedo_rl = 0;
	if(is_L[1]) psuedo_rl++;
	if(!is_L[N]) psuedo_rl++;
	int manipulation = min({lr, rl, K});
	happy += 2*manipulation;
	lr -= manipulation;
	rl -= manipulation;
	K -= manipulation;
	manipulation = 0;
	if(is_L[1]){
		if(lr > rl){
			manipulation = rl*2 + 1;
			lr -= rl + 1;
			rl = 0;
			is_L[1] = false;
		}else{
			manipulation = lr*2;
			lr = 0;
			rl -= lr;
		}
		if(manipulation >= K){
			printf("%d\n", happy + K);
			return 0;
		}
		happy += manipulation;
		K -= manipulation;
	}else{
		if(rl > lr){
			manipulation = lr*2 + 1;
			rl -= lr + 1;
			lr = 0;
		}else{
			manipulation = rl*2;
			rl = 0;
			lr -= rl;
		}
		if(manipulation >= K){
			printf("%d\n", happy + K);
			return 0;
		}
		happy += manipulation;
		K -= manipulation;		
	}
	if(!is_L[N]){
		if(lr > rl){
			manipulation = rl*2 + 1;
			lr -= rl + 1;
			rl = 0;
		}else{
			manipulation = lr*2;
			lr = 0;
			rl -= lr;
		}
		if(manipulation >= K){
			printf("%d\n", happy + K);
			return 0;
		}
		happy += manipulation;
		K -= manipulation;
	}else{
		if(rl > lr){
			manipulation = lr*2 + 1;
			rl -= lr + 1;
			lr = 0;
		}else{
			manipulation = rl*2;
			rl = 0;
			lr -= rl;
		}
		if(manipulation >= K){
			printf("%d\n", happy + K);
			return 0;
		}
		happy += manipulation;
		K -= manipulation;		
	}
	printf("%d\n", happy);
	return 0;
}