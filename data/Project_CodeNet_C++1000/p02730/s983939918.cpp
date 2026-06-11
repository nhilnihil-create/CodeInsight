#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-1-i])
            return 0;

    }
    return 1;
}
int main()
{
    string s,p="",m="";
    cin>>s;
    int n=s.length();
    if(check(s))
    {
        for(int i=0;i<(n-1)/2;i++)
        {
            p+=s[i];
        }
        if(check(p))
        {
            for(int i=(n+3)/2-1;i<n;i++)
            {
                m=m+s[i];

            }
            if(check(m))
                cout<<"Yes";
            else
                cout<<"No";
        }
        else
            cout<<"No";
    }
    else
        cout<<"No";
}