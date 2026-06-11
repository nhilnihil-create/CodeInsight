#include <bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outp.txt","w",stdout);
    #endif
    ll x,a,b,f=0;
    cin>>x;
    for(ll i=1;i<=1000;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(x%(i-j)==0)
            {
                if(pow(i,5)-pow(j,5)==x)
                {
                    a=i;b=j;
                    f=1;
                    break;
                }
            }
            if(x%(i+j)==0)
            {
                if(pow(i,5)+pow(j,5)==x)
                {
                    a=i;b=-j;
                    f=1;
                    break;
                }
            }
            if(f==1)
                break;
        }
    }
    cout<<a<<" "<<b;
}