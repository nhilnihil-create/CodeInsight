#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define repp(i,a,b) for(int i=a;i<b;i++)
#define mm(a,n) memset(a, n, sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define il inline
#define int long long
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pi 3.14159265358979323
#define SZ(x) ((ll)(x).size())
#define debug(x) 		cout<<#x<<": "<<x<<endl;
#define debug2(x,y)     cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define debug3(x,y,z)   cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define debug4(a,b,c,d) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
using namespace std;
const int N = 3e5 + 10;
struct Edge{
	int nex , to;
}edge[N << 1];
int head[N] , TOT;
void add_edge(int u , int v)
{
	edge[++ TOT].nex = head[u] ;
	edge[TOT].to = v;
	head[u] = TOT;
}
const long double eps = 1e-6;
signed main()
{
	ios;
	int a ;
	long double b;
	cin >> a >> b;
	b += eps;
	int d = b * 100;
	cout << (ll)(a * d / 100) << '\n';
	return 0;
}






