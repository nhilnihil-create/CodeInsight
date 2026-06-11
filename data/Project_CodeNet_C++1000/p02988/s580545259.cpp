#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    cin>>p[i];
    int a=0;
    for(int i=1;i<n-1;i++)
    {
        if(p[i-1]<p[i] && p[i]<p[i+1]) a++;
        if(p[i-1]>p[i] && p[i]>p[i+1]) a++;
    }
    cout<<a<<"\n";
}