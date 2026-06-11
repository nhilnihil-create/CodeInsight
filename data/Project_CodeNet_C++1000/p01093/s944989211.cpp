#include<stdio.h>

int ov_abs(int a){
    return a>0 ? a : -a;
}

int score[1000];
int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        int ans = 889464810;
        for(int i=0; i<n; i++){
            scanf("%d",&score[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int tmp = ov_abs(score[j]-score[i]);
                ans = ans > tmp ? tmp:ans;
            }
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }

    return 0;
}