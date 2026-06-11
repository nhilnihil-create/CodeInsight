#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        ans+=(n-1)/i;
    }
    cout<<ans<<endl;
    return 0;
}