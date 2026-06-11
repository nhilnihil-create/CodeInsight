#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;


int main(void){
    // Here your code !
    int n,s[1000];
    double m,A;
    while(1){
    cin>>n;
    if(n==0) break;
    m=0;
    A=0;
    for(int i=0;i<n;i++){

     
       cin>>s[i];
       m=m+s[i];
       
    }
    m=m/n;
    
    for(int i=0;i<n;i++){

       A=A+pow((s[i]-m),2);
       
    }
    A=A/n;
    A=sqrt(A);
    printf("%f\n",A);
    
}

}