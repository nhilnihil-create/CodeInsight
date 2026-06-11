#include<cstdio>
int main(){
    for(;;){
        int ai,bi,as=0,bs=0,n;
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d%d",&ai,&bi);
            if(ai>bi) as+=ai+bi;
            else if(ai<bi) bs+=ai+bi;
            else{
                as+=ai;
                bs+=bi;
            }
        }
        printf("%d %d\n",as,bs);
    }
}