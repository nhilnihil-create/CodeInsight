#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(s[2]==s[3]&&s[4]==s[5])
    cout<<"Yes\n";
    else
    cout<<"No\n";
}
