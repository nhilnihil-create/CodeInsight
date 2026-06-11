#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for0(n) for(i=0; i<(n); i++)
#define for1(n) for(i=1; i<=(n); i++)


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _,i,j,n,a,b,e,k,u,t,x=1,m,y,q,f=1,c=0,d=0,l,p,z,o,r,g;
    string ss,s;
    cin>>n;
    for(i=sqrt(n)+1;i>=1;i--)
    {
        if(n%i==0)break;
    }
    cout<<i+(n/i)-2<<endl;
}

