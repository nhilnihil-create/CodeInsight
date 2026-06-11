#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,r;
    cin>>s>>r;
    int c=0;
    if(s[0]==r[0])
    c++;
    if(s[1]==r[1])
    c++;
    if(s[2]==r[2])
    c++;
    cout<<c<<"\n";
}