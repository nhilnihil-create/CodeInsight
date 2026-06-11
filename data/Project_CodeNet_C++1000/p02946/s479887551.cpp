#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,x;
    cin>>k>>x;
    if(k==1)
    cout<<x;
    else
    {
        for(int i=x-k+1;i<k+x;i++)
        {
            cout<<i<<" ";
        }
    }
}