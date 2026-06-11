#include<stdio.h>

int main()
{
    int a[10], b[100] = {0}, bingo=0, x;
    scanf("%d%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&x);
    for(int i=0;i<x;i++){
        scanf("%d",&b[i]);
    }
    for(int i = 0; i<x;i++){
        for(int j=0;j<9;j++){
            if(b[i]==a[j]){
                a[j]=101;
            }
        }
    }
   if(a[0]==101&&a[1]==101&&a[2]==101){
       bingo++;
   }else if(a[3]==101&&a[4]==101&&a[5]==101){
       bingo++;
   }else if(a[6]==101&&a[7]==101&&a[8]==101){
       bingo++;
   }else if(a[0]==101&&a[3]==101&&a[6]==101){
       bingo++;
   }else if(a[1]==101&&a[4]==101&&a[7]==101){
       bingo++;
   }else if(a[2]==101&&a[5]==101&&a[8]==101){
       bingo++;
   }else if(a[0]==101&&a[4]==101&&a[8]==101){
       bingo++;
   }else if(a[2]==101&&a[4]==101&&a[6]==101){
       bingo++;
   }
   bingo>0?printf("Yes\n"):printf("No\n");
return 0;
}