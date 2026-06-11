#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll repow(ll k,ll n)
{
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans= (((ans)*k) )%mod;
    }
    return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    int n;
    cin>>n;
    cin>>a;
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        if(a[i]=='A' && a[i+1]=='B' && a[i+2]=='C')
            ans++;
    }
    cout<<ans;
}
