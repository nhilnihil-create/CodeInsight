#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
typedef pair<ll,ll> ipair;
#define F first
#define S second


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
	ll n,i,j,p,k,m,ans=0;
    cin>>n;
    vector<ll> a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    map<ll,ll> mp;
    for(i=0;i<n;i++)
    {
        mp[i+a[i]]++;
    }
    for(i=0;i<n;i++)
    {
        ans+=mp[i-a[i]];
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    // for(i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    
	return 0;
}