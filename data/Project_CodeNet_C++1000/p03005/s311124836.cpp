#include<stdio.h>
main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
            if(a==b||b==1||a<b){
                printf("0\n");
            }
            else{
                a=a-b;
                printf("%d\n",a);
            }
    }
}
