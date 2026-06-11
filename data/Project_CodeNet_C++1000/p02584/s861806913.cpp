#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

int main()
{
    long long int x,k,d,min;
    cin>>x>>k>>d;
    long long int m=abs(x);
    if(k<=m/d)
    {
        min=m-k*d;
    }
    else
    {
        if((k-(m/d))%2==0)
        {
            min=m%d; 
        }
        else
        {
            min=d-(m%d);  
        }
    }
    cout<<min;
}