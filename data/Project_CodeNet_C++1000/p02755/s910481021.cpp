#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll n,a,b,i,j;
    cin>>a>>b;
    for(i=1;i<=1000000;i++)
    {
        long double x,y;
        x=i*0.08;
        y=i*0.1;
        ll c,d;
        c=floor(x);
        d=floor(y);
        if(c==a && d==b) 
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}