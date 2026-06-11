#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,u;
    int a,b,d,e;
    cin>>s>>t;
    cin>>a>>b;
    cin>>u;
    if(u==s)
    {
        d=a-1;
        cout<<d<<" "<< b<<endl;
    }
    else if(u==t)
    {
        e=b-1;
        cout<<a<<" "<< e<<endl;
    }
    return 0;
}
