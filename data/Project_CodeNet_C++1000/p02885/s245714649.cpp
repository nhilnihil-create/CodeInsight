#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(b>=a || 2*b>=a)
    cout<<0<<"\n";
    else if(a>b)
    cout<<(a-2*b)<<"\n";
}