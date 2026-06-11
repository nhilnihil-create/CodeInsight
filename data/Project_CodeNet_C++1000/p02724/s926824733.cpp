#include<stdio.h>
 int main(){
 int x;
 scanf("%d",&x);
 int c500 = x/500; // 500 円硬貨の数
 int r500 = x%500; // 端数
 int c5 = r500/5; // 5 円硬貨の数
 printf("%d\n",c500*1000+c5*5);
 }
