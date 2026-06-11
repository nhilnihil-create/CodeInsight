#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n,d,a,b,c,num=0;
    cin>>n>>d;
    while(n--)
    {
        cin>>a>>b;
        a=pow(a,2);
        b=pow(b,2);
        c=pow(a+b,0.5);
        if (c<=d)
            num+=1;
    }
    cout<<num<<endl;
}
