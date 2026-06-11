#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,x;
    cin>>n;
    double sum=0.0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        sum+=(1.0/x);
    }
    sum=1.0/sum;
    cout<<setprecision(16)<<sum<<"\n";
    
}