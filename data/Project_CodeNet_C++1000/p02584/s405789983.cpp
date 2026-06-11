#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    if(x==0) 
    {
        if(k%2) cout<<d-x;
        else cout<<0;
    }
    else if(x/d>=k){
        x=x-(k*d);
        cout<<abs(x);
       
    }
    else
    {
        l=x/d;
        x-=(l*d);
        k-=(l);
        if(k%2) cout<<d-x;
        else cout<<x;
    }
    
    return 0;
}