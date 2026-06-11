#include<cstdio>

int main(void){
    int a=0,b=0,change=0;
    while(true){
        scanf("%d %d",&a,&b);
        if((a==0)&&(b==0)){
            break;
        }
        if(b<a){
            change=a;
            a=b;
            b=change;
        }
        printf("%d %d\n",a,b);
        
    }
    return 0;
}
