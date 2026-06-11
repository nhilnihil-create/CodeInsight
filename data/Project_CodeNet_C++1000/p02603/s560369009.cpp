#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fs first
#define se second
#define M 1000000007
#define pii pair<long long,long long>
 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
unordered_map<char,pii>dir;
ll D=1e9;
 
bool check(ll x,ll y,ll n,ll m){
	return (x>=0 && y>=0 && n>x && m>y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	ll n;
	cin>>n;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ll p=1000,net=0;
	ll ans=0;
	ll mn=arr[0];
	ll mx=arr[0];
	for(ll i=1;i<n;i++)
	{
		if(mx<arr[i])
			mx=arr[i];
		else
		{
			net=p/mn;
			p=p%mn;
			p+=net*mx;
			mn=arr[i];
			mx=arr[i];
		}
	}

	net=p/mn;
	p=p%mn;
	p+=net*mx;
	cout<<p<<endl;

}

