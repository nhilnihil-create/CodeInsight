#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define M 1000000007
#define ll long long int
#define F first
#define S second
#define INF (ll)1000000000
const int N = 1e5 + 5;
#define maax(a,b,c) max((int)a,max((int)b,(int)c))
#define miin(a,b,c) min((int)a,min((int)b,(int)c))
#define mp make_pair
#define in long long int
#define ep emplace_back
#define all(a) a.begin(),a.end()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define inf (long long) 1e18
#define vl vector<ll>
#define sz(a) (ll)a.size()
#define mem(a,b) memset(a,b,a.size())
#define fr(i,m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define fre(i,m, n) for (int i = (int)(n); i <= (int)(m); i--)
#define rall(x) (x).rbegin(), (x).rend()
typedef long long LL;
typedef pair<int, int> PII;	
int solve()
{
	
    return 0;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
    int a[3][3];
    fr(i,0,3) 
    {
    	fr(j,0,3)
    	{
    		cin>>a[i][j];
		}
	}
	int f=0,t;cin>>t;vector<int>b(t);map<int,int>m;
	while(t--) cin>>b[t],m[b[t]]++;
	fr(i,0,3) 
	{
		if((m[a[0][i]]+m[a[1][i]]+m[a[2][i]])>2)
		{
			cout<<"Yes\n";return 0;
		}
		if((m[a[i][0]]+m[a[i][1]]+m[a[i][2]])>2)
		{
			cout<<"Yes\n";return 0;
		}
	}
	((m[a[0][0]]+m[a[1][1]]+m[a[2][2]])>2 || (m[a[0][2]]+m[a[1][1]]+m[a[2][0]])>2)?cout<<"Yes":cout<<"No";
	return 0;
}
