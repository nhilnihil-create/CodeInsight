#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
int main()
{
    int k,x;
    cin>>k>>x;
    if(k*500>=x)
        cout<<"Yes"<<'\n';
    else if(k*500<x)
        cout<<"No"<<'\n';
}

