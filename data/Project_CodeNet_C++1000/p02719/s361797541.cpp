#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k;
    cin>>n>>k;
    if(n==k)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(n>k)
    {
        long long int ans = n%k;
        ans = min(ans,abs(k-ans));
        cout<<ans<<"\n";
    }
    else
    {
        long long int ans = min(n,abs(k-n));
        cout<<ans<<"\n";
        return 0;
    }
    
}