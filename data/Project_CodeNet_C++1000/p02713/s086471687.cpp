#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll gcd (ll p, ll q)
{
    if (q==0) {return p;}
    return gcd(q,p%q);
}

int main(){
    ll n,i,j,k,s=0,l; cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        { l=gcd(i,j);
            for(k=1;k<=n;k++)
            {
                s+=gcd(l,k);
            }
        }
    } cout<<s;
    return 0;
}
