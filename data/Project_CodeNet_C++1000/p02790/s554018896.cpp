#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    char c;
    cin>>a>>b;
    string s1="",s2="";
    for(int i=0; i<a; i++)
    {
        c=b+'0';
        s1+=c;
    }
    for(int i=0; i<b; i++)
    {
        c=a+'0';
        s2+=c;

    }
    if(s1.size()>s2.size())
    {
        for(int i=0; i<s1.size(); i++)
        {
            if((s1[i]-'0')<(s2[i]-'0'))
            {
                cout<<s1;
                return 0;
            }
            else if((s1[i]-'0')>(s2[i]-'0'))
            {
                cout<<s2;
                return 0;
            }
        }
    }
    else
    {
        for(int i=0; i<s2.size(); i++)
        {
            if((s1[i]-'0')<(s2[i]-'0'))
            {
                cout<<s1;
                return 0;
            }
            else if((s1[i]-'0')>(s2[i]-'0'))
            {
                cout<<s2;
                return 0;
            }
        }
    }
    cout<<s1;
    return 0;
}