#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9;

int main()
{
    ll s;
    ll x2,y2,x3,y3;
    cin>>s;
    if(s>mod)
    {
        if(s/mod==mod)
        {  
            x2=mod;
            y2=0;
            x3=0;
            y3=mod;

        }
        else
        {
            ll q=s/mod;
            ll r=s%mod;
            x2=mod;
            y2=1;
            x3=mod-r;
            y3=q+1;
            
        }
        
        

    }
    else
    {
        x2=s;
        y2=0;
        x3=0;
        y3=1;
    }
    
    


     cout<<0<<" "<<0<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
    
}
