#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int a=0,b=0,c=0;
    if(n==3 && s[0]==s[2])
        {cout<<"Yes\n";return 0;}
    for(int i=0;i<(n-1)/4;i++)
    {
        if(s[i]!=s[(n-1)/2-i-1])
            {a++;break;}
    }
    for(int i=0;i<(n-1)/2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            b++;break;
        }
    }
    int x=0;
    for(int i=(n+3)/2-1;i<(3*n+3)/4;i++)
    {
        if(s[i]!=s[n-x-1])
        {
            c++;break;
        }
        x++;
    }
    //cout<<a<<" "<<b<<" "<<c<<"\n";
    if(a==0 && b==0 && c==0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}