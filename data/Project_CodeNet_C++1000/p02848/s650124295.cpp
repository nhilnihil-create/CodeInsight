#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(char c:s)
    {
        int x=c-'A';
        x=(x+n)%26;
        putchar('A'+x);
    }
    
}