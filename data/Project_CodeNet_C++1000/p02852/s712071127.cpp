#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int N, M;
	char S[100010];
	
	scanf("%d %d", &N, &M);
	scanf("%s", S);
	
	int count = 0;
	int now = N;
	int history[100001];
	
	while(now > 0){
		for(int i = M; i > 0; i--){
			if(S[now-i] == '0'){
				now = now - i;
				history[count] = i;
				count++;
				break;
			}
			if(i == 1){
				now = -1;
			}
		}
	}
	
	if(now == -1){
		printf("-1\n");
	}else{
		for(int i = 0; i < count; i++){
			printf("%d ", history[count - i - 1]);
		}
			printf("\n");
	}
	
	return 0;
}