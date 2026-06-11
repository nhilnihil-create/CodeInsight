#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,t;
    int i,n,r=0;
    cin>>s>>t;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            r++;
        }
    }
    if(r==0)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}