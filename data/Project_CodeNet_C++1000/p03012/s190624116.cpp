#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    int w[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    int mini=sum;
    int pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=w[i];
        mini=min(mini,abs(pre-(sum-pre)));
    }
    cout<<mini<<"\n";
}