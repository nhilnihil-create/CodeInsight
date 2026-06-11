#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef queue<char> qc;
typedef queue<string> qs;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<char,int> mpci;
typedef map<int,int> mpii;
typedef map<string,int> mpsi;
typedef set<int> sei;
typedef set<char> sec;
typedef set<string> ses;
typedef stack<ll> si;
typedef stack<char> sc;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pll> vpll;
typedef vector<pdd> vdd;
typedef unsigned int uint;
typedef long double ld;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;
/*=====================================================================*/
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define all(s) (s).begin(),(s).end()
#define fi first
#define se second
#define be begin
#define en end
#define m_p make_pair
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define forn(i,p,n) for(int i=p;i<=n;i++)
#define ford(i,p,n) for(int i=n;i>=p;i--)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define zero(a) memset(a,0,sizeof(a))
#define number(a,num) memeset(a,num,sizeof(a))
#define INF 1e9

/*=====================================================================*/

inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
inline void write(long long x) {
  static long long sta[35];
  long long top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
  puts("");
}
void finish(string s)
{
	cout<<s<<endl;
	exit(0);
}
string int_to_string(int n)
{
	string s="";
	while(n)
	{
		int now=n%10;
		s+=now+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int string_to_int(string s)
{
	int n=0;
	rep(i,s.size())
	{
		n*=10;
		n+=s[i]-'0';
	}
	return n;
}
/*======================================================================*/
ll lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}
bool prime(int n)
{
	if(n==0||n==1)
	  return false;
	for(int i=2;i*i<=n;i++)
	  if(n%i==0)
	    return false;
	return true;
}
const ll power(int n,int k)
{
	ll t=1;
	rep(i,k)
	  t*=n;
	return t;
}
const string turn2(int n)
{
	string s="";
	while(n!=0)
	{
		s+=(char)(n%2+'0');
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
string turn(int n,int k)
{
	string s="";
	while(n)
	{
		s+=(char)(n%k+'0');
		n/=k;
	}
	reverse(s.begin(),s.end());
	return s;
}
const string turn16(int n)
{
	string s="";
	while(n!=0)
	{
		if(n%16>9)
		  s+=(char)('A'+n%16-10);
		else
		  s+=(char)('0'+n%16);
		n/=16;
	}
	reverse(s.begin(),s.end());
	return s;
}
const ll quickpower(int n,int k)
{
	if(k==1)
	  return n;
	if(k%2==1)
	  return n*quickpower(n,k/2)*quickpower(n,k/2);
	else
	  return quickpower(n,k/2)*(quickpower(n,k/2));
}
/*======================================================================*/
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
ll n,k;
vll a,b;
bool check(ll mid)
{
	ll cnt=0;
	vll v;
	rep(i,n)
	{
		v.pb(mid/b[i]);
	}
	sort(all(v));
	rep(i,n)
	{
		if(a[i]>v[i])
		{
			cnt+=(a[i]-v[i]);
		}
	}
	return cnt<=k;
}
/*======================================================================*/
int main()
{
  /*
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
  */
  /*====================================================================*/
  cin>>n>>k;
  int u;
  rep(i,n)
  {
  	cin>>u;
  	a.pb(u);
  }
  rep(i,n)
  {
    cin>>u;
  	b.pb(u);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll l=0,r=2e18;
  while(l<=r)
  {
		ll mid=(l+r)/2;
		//cout<<mid<<endl;
		if(check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
  cout<<l<<endl;
  return 0;
}

