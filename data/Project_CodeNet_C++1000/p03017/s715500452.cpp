#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,a,b,c,d,i;
    bool flg=false;
    string str;
    cin>>n>>a>>b>>c>>d;
    a--;b--;c--;d--;
    cin>>str;
    if(a<c && c<b)
    {
        for(i=a;i<c;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
        for(i=b;i<d;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
    }
    else if(a<b && b<c && c<d)
    {
        for(i=b;i<d;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
        for(i=a;i<c;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
    }
    else if(a<b && b<d && d<c)
    {
        for(i=a;i<c;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
        for(i=b;i<d;i++)
        {
            if(str[i]=='#' && str[i+1]=='#')
            {
                cout<<"No";
                return 0;
            }
        }
        for(i=b-1;i<=d-1;i++)
        {
            if(str[i]=='.' && str[i+1]=='.' && str[i+2]=='.')
            {
                flg=true;
                cout<<"Yes";
                return 0;
            }
        }
        if(flg==false)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}
