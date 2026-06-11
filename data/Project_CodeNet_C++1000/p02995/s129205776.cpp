#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    long long int a,b,c,d,num1,num2,num3,num;
    cin>>a>>b>>c>>d;
    num=b-a+1;
    long long int lcd=(c*d)/gcd(c,d);
    if(a%c==0){
        num1=(b/c)-(a-1)/c;
    }
    else{
         num1=(b/c)-(a/c);
    }
    if(a%d==0){
        num2=(b/d)-(a-1)/d;
    }
    else{
         num2=(b/d)-(a/d);
    }
    if(a%lcd==0){
        num3=(b/lcd)-(a-1)/lcd;
    }
    else{
         num3=(b/lcd)-(a/lcd);
    }

   cout<<(num-num1-num2+num3);
}