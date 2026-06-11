#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define PI			2*acos(0.0)
int main()
{
    int n,i;
    cin >>n;
    int a[n+1],b[n+1];
    for(i=1;i<=n;i++)
    {
        cin >>a[i];
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        cout <<b[i]<<' ';
    }
    return 0;
}