#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

lli p,n;
string str;

int main()
{
    cin>>n>>p;
    cin>>str;

    lli ans=0;
    if(p==2)
    {
        for(lli i=0;i<n;i++)
        {
            if( (str[i]-'0') %2==0)
            {
                ans+=i+1;
            }
        }
    }
    else if(p==5)
    {
        for(lli i=0;i<n;i++)
        {
            if( (str[i]-'0')%5==0)
            {
                ans+=i+1;
            }
        }
    }
    else{

        map<lli,lli> m;
        m[0]++;
        lli r=1;
        lli t=0;
        for(lli i=n-1;i>=0;i--)
        {
            t=(t+(str[i]-'0')*r)%p;
            //cout<<t<<"\n";
            ans+=m[t];
            m[t]++;
            r=(r*10)%p;

        }
    }
    cout<<ans<<"\n";
    return 0;
}
