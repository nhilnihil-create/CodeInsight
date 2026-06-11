#include<bits/stdc++.h>
#include <iostream>
#include <list>
#define ll long long int
using namespace std;
int main()
{
    int t,m,i,cnt=0;cin>>t;
    int ara[t];
    for( i=1;i<=t;i++)cin>>ara[i];
    for( i=1;i<=t;i+=2)
    {
        if(ara[i]%2)cnt++;
    }
    cout<<cnt<<"\n";
}

