#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(n) for(i=0; i<(n); i++)
#define for1(n) for(i=1; i<=(n); i++)
#define M 1000000007


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _,i,j,n,a,b,e,k,u,t,x=1,m,y,q,f=1,c=0,d=0,l,p,z,o,r,g;
    string ss,s;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        if(x==y)c++;
        else c=0;
        if(c>=3)d=1;
    }
    cout<<(d?"Yes":"No")<<endl;
}

