#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,p="ABC";
    int n,res=0;
    cin>>n>>s;
    for(int i=0;i<=n-3;i++)
    {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
        res++;
    }
    cout<<res<<"\n";
}