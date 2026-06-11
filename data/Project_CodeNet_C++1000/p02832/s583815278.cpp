#include<bits/stdc++.h>
#define ll long long

 
using namespace std;
int main()
{
    ll n, temp;
    cin>>n;
    ll j=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        if(temp==j)
        {   j++;
            ans++;
        }
    }
    if(ans==0)
        cout<<"-1\n";
    else
        cout<<n-ans<<"\n";
    
}