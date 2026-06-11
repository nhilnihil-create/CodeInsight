#include<cstdio>

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        bool a = false;
        if(i % 3 == 0){
            a = true;
        }
        else if(i % 10 == 3){
            a = true;
        }
        else if((i / 10) % 10 == 3){
            a = true;
        }
        else if((i / 100) % 10 == 3){
            a = true;
        }
        else if((i /1000) % 10 == 3){
            a = true;
        }
        if(a){
            printf(" %d",i);
        }
    }
    printf("\n");
    return 0;
}
