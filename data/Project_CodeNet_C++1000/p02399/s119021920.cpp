#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    double a1,b1;
    a1 = a;
    b1 = b;
    printf("%d %d %.5f\n",(a/b),(a%b),(a1/b1));
    return 0;
    
}
