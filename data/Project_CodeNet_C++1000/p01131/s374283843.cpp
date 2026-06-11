#include<stdio.h>
#include<string.h>
main(){
    int N;
    char S[1025];
    scanf("%d",&N);
    char str[][6] = {".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(int i = 0;i < N;i++){
        scanf("%s",S);
        int num = 0;//?????¨??\??????????????????
        int count = 0;
        for(int j = 0;j < strlen(S);j++){
            if(S[j] != '0'){num = S[j] - '0';}
            if(S[j] == '0' && num == 0){continue;}
            if(S[j] == S[j+1]){
                count++;
                continue;
            }
            printf("%c",str[num-1][count%(strlen(str[num-1]))]);
            count = 0;
            num = 0;
        }
        printf("\n");
    }
}