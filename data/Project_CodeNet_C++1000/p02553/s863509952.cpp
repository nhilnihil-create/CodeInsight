#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    long long int op1=a*c;
    long long int op2=a*d;
    long long int op3=b*c;
    long long int op4=b*d;
    printf("%lld\n",max({op1,op2,op3,op4}));
    return 0;
}
