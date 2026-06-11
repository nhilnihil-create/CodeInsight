#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 

void solve()
{
	ll n;
	cin>>n;
	vector<pair<ll,ll>> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	sort(a.begin(),a.end(), sortbysec);
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		cnt+=a[i].first;
		if(cnt>a[i].second)
		{
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
	return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}