/*
	Name:
	Author: xiaruize
	Date:
*/
#pragma GCC optimize(2)
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

inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}

ll a[100005];
ll suf[100005];
ll ans[100005];

int main()
{
 	ios::sync_with_stdio(false);
	cin.tie(0);
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=0;i--)
	{
		suf[i]=suf[1+i]+a[i];
	}
	ans[0]=1;
	for(int i=1;i<=n;i++)
	{
		ans[i]=min((ans[i-1]-a[i-1])*2,suf[i]);
	}
	for(int i=0;i<=n;i++)
		if(ans[i]<a[i])
		{
			cout<<"-1"<<endl;
			return 0;
		}
	ll res=0;
	for(int i=0;i<=n;i++)
	{
		res+=ans[i];
	}
	cout<<res<<endl;
	return 0;
}
