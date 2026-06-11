#include<stdio.h>
 
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    
    int score[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }
    for(int i = K; i < N; i++) {
        if(score[i] > score[i - K]) {
            printf("Yes\n");
        } 
		else {
            printf("No\n");
        }
    }
    return 0;
}