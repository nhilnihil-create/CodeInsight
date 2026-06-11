#include<bits/stdc++.h>
#define ll long long int
#define ar array
#define pb push_back
#define input(arr,n) for(int i = 0; i<n; i++) cin>>arr[i]
const int mod = 1e9+7;
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	if(s.back()!='s') s += "s";
	else s += "es";
	cout<<s<<endl;
	return 0;
}