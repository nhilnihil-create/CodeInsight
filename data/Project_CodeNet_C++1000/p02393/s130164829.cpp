#include <cstdio>
#include <iostream>

using namespace std;

void swap(int &x,int &y){
     int temp;
     temp = x;
     x = y;
     y = temp;
     }

main(){
       int a,b,c;
       scanf("%d %d %d",&a,&b,&c);
       if(a > b)swap(a,b);
       if(a > c)swap(a,c);
       if(b > c)swap(b,c);
       printf("%d %d %d\n",a,b,c);
       return 0;
       }