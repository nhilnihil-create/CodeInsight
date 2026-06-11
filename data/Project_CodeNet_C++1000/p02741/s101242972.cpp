#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define pii pair<ll,ll>
#define sz(v) (v).size()
#define srt(v) sort(v.begin(),v.end())
#define ull unsigned long long
#define tell(a) cout<<a<<" "
#define el cout<<endl
#define rev(v) reverse(v.begin(),v.end())
#define rep(i,a,n) for(int i=a;i<n;i++)
#define M 1000000007
ll power(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){   if (y & 1)res = (res*x) % p;y = y>>1;
x = (x*x) % p;}return res;}



int main()
{
	IOS;
	int a[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin>>k;
	cout<<a[k-1];
}

