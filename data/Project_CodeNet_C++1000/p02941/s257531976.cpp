/*
Code Author: ADITYA SHETH (^_^)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	set<pair<int,int>>se;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		se.insert({b[i],i});
	}
	int ans=0;
	while(se.size())
	{
		auto pt=se.end();
		pt--;
		auto tmp=*pt;
		se.erase(pt);
		int i=tmp.second;
		if(b[i]==a[i])
		{
			continue;
		}
		int k=(b[i]-a[i])/(b[(i+1)%n]+b[(i+n-1)%n]);
		ans+=k;
		if(k==0)
		{
			cout<<"-1\n";
			return 0;
		}

		b[i]-=k*((b[(i+1)%n]+b[(i+n-1)%n]));
		se.insert({b[i],i});
	}	
	cout<<ans<<endl;
	return 0;
}
