#include<stdio.h>
int main(){
    int l, r, d, ctr=0;
    scanf("%d %d %d", &l, &r, &d);
    
    for(int i=l; i<=r; i++){
        if(i%d == 0){
            ctr++;
        }
    }
            printf("%d ", ctr);

    return 0;
}


