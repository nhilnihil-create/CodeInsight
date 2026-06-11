///I am Groot |*|
///19.09.2020>>01.59 PM
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int a,b,c,d,x[3],max;
    cin>>a>>b>>c>>d;
    max=a*c;
    x[0]=a*d;
    x[1]=b*c;
    x[2]=b*d;
    for(int i=0; i<3; i++)
    {
        if(max<x[i])
        {
            max=x[i];
        }
    }
    cout<<max;
}
