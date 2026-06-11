#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        int m=floor((n+0.0)/i);
        sum+=(long long int)m*(m+1)*i/2;
    }
    cout<<sum;
}

