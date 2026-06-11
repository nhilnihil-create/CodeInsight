#include<bits/stdc++.h>
using namespace std;
#define ll long long

main()
{
    int t=1;
    while(t--){
    ll n,k,ans;
    cin>>n>>k;
    ll x=n%k;
    ans=abs(x-k);
    ans=min(ans,abs(ans-k));
    cout<<min(ans,n)<<endl;
    }
}
