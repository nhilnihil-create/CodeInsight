#include<bits/stdc++.h>
using namespace std;

#define                                 ff                                          first
#define                                 ss                                          second
#define                                 pai                                         acos(-1)
#define                                 ll                                          long long


const ll mod  = 1e9 +07;
const ll mxn  = 1e6 +10;

int  main()
{
    ll i,j,k,a,b,c,d,n,m,t,h,u,v,x,y,z;
    string s;
    cin>>s;
    if(s[0]=='R'&&(s[0]==s[1]&&s[1]==s[2]))
    {
        cout<<3<<endl;
    }
    else if(s[1]=='R'&&(s[0]==s[1]||s[1]==s[2]))
    {
        cout<<2<<endl;
    }
    else if(count(s.begin(),s.end(),'R')>0)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}

