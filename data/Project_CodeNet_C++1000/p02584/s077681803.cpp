/*                                  /   \                                                                   (Hello)//JSM//*/      
/*                                 /*****\                                                                              */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K                                                            */
#include<bits/stdc++.h>            
#include<cmath>                  
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define pb push_back 
#define mkp make_pair    
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define rall(v )  reverse(v.begin(), v.end())      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vll vector< pair<ll,ll> > 
#define mpl map<ll, ll>
#define ee cout<<endl
#define pr pair<ll,ll>
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x*x)%MOD;if(p%2==0) return x;else return (x*n)%MOD;}
/*ll vis[100023];
ll a[100023];
vl v0[100023];
vl v1[100023];
vl V[100023];
ll col[100023];
ll ans=0;
vl L[100023];
ll mx=0;
void dfs(ll node,ll f)
{
	if(vis[node]==1)
	return;
	vis[node]=1;
	mx=max(mx,f);
	L[f].pb(node);
	for(i=0;i<V[node].size();i++)
	{
		dfs(V[node][i],f+1);
	}
}
*/
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;
	   //cin>>t;
	      while(t--)
{
/*
7 4 3*/
ll  n,m;
ll k;
cin>>n>>k>>m;
n=abs(n);
if(n/m>=k)
cout<<n-m*k;
else
{k-=n/m;
n-=(n/m)*m;
k=k%2;
if(k==0)
cout<<abs(n);
else
cout<<abs(n-m);
}
ee;
/*
5
4 4 9 7 5*/
/*ll n,j,k,l,i,m;
cin>>n;
ll a[n];
fo(i,n)
cin>>a[i];
//sort(a,a+n);
ll ans=0;
for(i=0;i<n-2;i++)
{
	for(j=i+1;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[k]+a[j]>a[i]&&a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k])
			ans++;
		}
	}
}
cout<<ans;
ee;
*/
	/*
string a;
ll c=0,i;
ll mx=0;
cin>>a;
fo(i,a.length())
{
	if(a[i]=='R')
	c++;
	else
	c=0;
	mx=max(mx,c);
}
cout<<mx;
ee;*/
/*ll n,m,j,k,l,i;
cin>>n;
ll a[n],b[n];
string s;
fo(i,n-1)
{
	cin>>a[i]>>b[i];
	V[a[i]].pb(b[i]);
	V[b[i]].pb(a[i]);
}
cin>>s;
ans=0;
mx=0;
fo(i,n)
vis[i+1]=0;
dfs(1,1);
ll h=2;
ans=0;
for(i=mx;i>=1;i--)
{
	if(L[i].size()>=h)
	{
		ans=-1;
		break;
	}
}
*/

/*
1  
7  
1 2  
1 3  
2 4  
2 5  
3 6  
3 7  
0010010*/
}
return 0;
}














