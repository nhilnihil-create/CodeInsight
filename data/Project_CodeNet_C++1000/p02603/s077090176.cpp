#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f(i,l,u) for(ll i=l;i<u;i++)
int main() {
    ll n;
    cin>>n;
ll a[n+1];


f(i,0,n)
cin>>a[i];

ll buy=1;
ll temp=0;
ll qty;
ll bal=1000;
while(temp<n)
{
    if(buy)
    {
        while(a[temp+1]<=a[temp])
        {
            temp++;
            if(temp==n-1)
            break;
        }
        if(temp==n-1)
        break;
        else
        {
          // / cout<<"buyed at "<<a[temp]<<endl;
    
            qty=bal/a[temp];
            bal-=qty*a[temp];
                      //  cout<<"avail bal= "<<bal<<endl;
            buy=0;
            
        }
        
    }
    else
    {
        while(temp<n-1&&a[temp+1]>=a[temp])
        {
            temp++;
        }
        
        
        buy=1;
        bal+=qty*a[temp];
    //    cout<<"sold at "<<a[temp]<<endl;
    //    cout<<"avail bal= "<<bal<<endl;
        
    }
    
}
cout<<bal<<endl;


}