#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[10];
    cin>>s;
    sort(s,s+4);
    if(s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3])
    cout<<"Yes\n";
    else
    cout<<"No\n";
}