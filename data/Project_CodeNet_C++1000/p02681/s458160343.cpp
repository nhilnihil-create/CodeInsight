#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;

    t.resize(s.size());

    if(s.compare(t)==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}