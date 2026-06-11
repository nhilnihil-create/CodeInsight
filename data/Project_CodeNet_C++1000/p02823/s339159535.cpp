#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    
        ll n,a,b;
    cin>>n>>a>>b;
    
        if((b-a)%2==0)
        cout<<(b-a)/2;
        else
        {
            ll ans=(a-1<n-b)?a-1:n-b;
            cout<<ans+1+((b-a)/2);
        }
        
    
    
    
}