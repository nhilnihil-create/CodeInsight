/*
	Name:
	Author: xiaruize
	Date:
*/

#include<algorithm>
#include<bitset>
#include<cctype>
#include<cerrno>
#include<clocale>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<utility>
#include<vector>
#include<cwchar>
#include<cwctype>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
#define ALL(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long
#define form(i,j,n) for(int i=int(j);i<=int(n);i++)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define sec second
#define sz(a) int((a).size())
ll ksm(ll a,ll b){ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}

ll s[100005];
ll ans;

int main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=k;i>=1;i--)
	{
		ll x=k/i;
		s[i]+=ksm(x,n);
		for(int j=i*2;j<=k;j+=i)
		{
			s[i]=(s[i]-s[j]+MOD)%MOD;
		}
		ans=(ans+s[i]*i%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}