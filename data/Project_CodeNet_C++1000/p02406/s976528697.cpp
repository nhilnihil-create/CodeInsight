
#include<cstdio>
int main(){
    int N;
    scanf("%d",&N);
    for(int n = 1; n <= N; n++){
        if(n % 3 == 0){
            printf(" %d",n);
        }
        else{
            int Q = n;
            int r;
            for(int j = 1;; j++){
                r = Q % 10;
                Q = Q / 10;
                if(r == 3){
                    printf(" %d",n);
                    break;
                }
                if(Q == 0){
                    break;
                }
            }
        }
    }
    printf("\n");

    return 0;
}
