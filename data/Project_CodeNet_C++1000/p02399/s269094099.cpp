#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
   int a,b,d,r;
       float f;
   cin>>a>>b;
   d=a/b;
   r=a%b;
   cout<<d<<" "<<r<<" ";
   printf("%.5lf\n",(double)a/b);
}
