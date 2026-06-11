#include <stdio.h>
 
int main(){
    int N;
    scanf("%d",&N);
    char S[10101];
    getchar();
    scanf("%[^\n]", S);
    
    for (int i = 0; S[i] != '\0'; i++){
        if(S[i] >= 'A' && S[i] <= 'Z'){
            S[i] += N;
            if(S[i] > 90){
                S[i] -= 26;
            }
            printf("%c",S[i]);
        }
    }
	return 0;
}