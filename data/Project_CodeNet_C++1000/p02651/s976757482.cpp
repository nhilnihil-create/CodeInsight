#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin,(x).end()
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define SID set<int>::iterator
#define fastCin ios::sync_with_stdio(false)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const db pi=acos(-1);
const int mod=1e9+7;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll quickpow(ll x,ll k) //x^k
{
	ll ans=1;
	while (k)
	{
		if (k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
ll v[100];

void ins(ll x)
{
	for (int i=63;i-- && x;)
	{
		if ((x>>i)&1) x^=v[i];
		if ((x>>i)&1) {v[i]=x;break;}
	}
}

bool que(ll x)
{
	for (int i=63;i-- && x;) if ((x>>i)&1) x^=v[i];
	return !x;
}

int n,t;
ll a[1000];
string s;

int main()
{
	fastCin;
	cin>>t;
	while (t--)
	{
		memset(v,0,sizeof(v));
		cin>>n;
		rep(i,1,n) cin>>a[i];
		cin>>s;
		bool bo=0; 
		per(i,n,1)
		{
			if (s[i-1]=='1')
			{
				if (!que(a[i]))
				{
					puts("1");
					bo=1;
					break;
				}
			}
			else ins(a[i]);
		}
		if (!bo) puts("0");
	} 
	return 0;
}
