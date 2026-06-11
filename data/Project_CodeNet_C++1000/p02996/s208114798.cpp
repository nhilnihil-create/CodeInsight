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
    vector<pair<ll,ll> > a(n);
    for(i=0;i<n;i++)
    {
        cin>>p>>k;
        a[i]={k,p};
    }
    sort(a.begin(),a.end());
    ll TIME = 0;ans=0;
    for(i=0;i<n;i++)
    {
        if(TIME+a[i].S>a[i].F)
        {
            ans=-1;break;
        }
        TIME+=a[i].S;
        
    }
    if(ans==-1)
    {
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
    
    
	return 0;
}