#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	// cin>>t;
	t=1;
	while(t--)
	{
		ld a,b,c;
		cin>>a>>b>>c;
		c=c-a-b;
		c/=2.000;
		ld xx=a*b;
		xx=sqrtl(xx);
		c/=xx;
		if(c>1)
		cout<<"Yes";
		else
		cout<<"No"; 
	}
	
}