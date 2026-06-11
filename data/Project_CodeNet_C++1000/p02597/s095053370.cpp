
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100000000
#define pb push_back
#define mp make_pair
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define all(v) (v).begin(),(v).end()


ll md=1e9+7;
ll __gcd(ll a, ll b) {if(b==0) return a; return __gcd(b, a%b);}
ll poww(ll a, ll b) {ll res=1;while(b) {if(b&1){res*=a;res%=md;}a*=a;a%=md;b>>=1;}return res;}
void ainp(int arr[], int n) {for(int i=0;i<n;i++) cin>>arr[i];}

const ll N=3e5+5;

void fun()
{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);}


signed main()
{  
fun();
int t;
//cin>>t;
t=1;
while(t--)
{
	int r=0,w=0,n,i;
	cin>>n;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='R')
		r++;
	}
	for(i=0;i<r;i++)
	{
		if(s[i]=='W')
		w++;
	}
	cout<<w;
}
}

