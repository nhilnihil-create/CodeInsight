#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) { 
    return (a.second < b.second); 
}
int main()
{
	fast;
	ll n,a,b,sum=0;
	cin>>n;
	vector<pair<int,int>> v;
	for(ll i=0;i<n;i++)
	{
		cin>>a>>b;
		sum+=a;
		v.push_back({a,b});
	}
	sum=0;
	sort(v.begin(),v.end(),sortbysec);
	for(int i=0;i<n;i++){
		sum+=v[i].first;
		if(sum>v[i].second)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
