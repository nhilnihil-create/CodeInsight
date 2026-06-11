#include<iostream>
#include<stdio.h>

using namespace std;
int main(){
int c,e,d,r;
double a,b,f;
      cin>>a>>b;
      d=a/b;
      c=a; 
      e=b;
      r=c%e;
      f=a/b;
         cout<<d<<" "<<r<<" ";
         printf("%.5f",f);
         cout<<endl;
         return 0;
}