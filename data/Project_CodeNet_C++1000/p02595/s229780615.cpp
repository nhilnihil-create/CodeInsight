#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    int n,d;
    cin>>n>>d;
    int a,b,ct=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        if((int)ceil(sqrt(pow(a,2) + pow(b,2))) <=d)
            ct++;
    }
    cout<<ct;
    return 0;
}
