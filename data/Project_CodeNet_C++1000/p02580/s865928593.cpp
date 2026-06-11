#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a+b);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a-b);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}
//	x<<1 => x*2		x>>1 => x/2;	cout<<flush;
//	cout<<fixed<<setprecision(10)<<ans<<endl;


void solve()
{
	int n, m, c;
	cin >> n >> m >> c;
	vector<pair<int, int>> sx(n), sy(m);
	for (int i = 0; i < n; i++) {
		sx[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		sy[i].second = i;
	}
	set<pair<int, int>> a;
	for (int i = 0; i < c; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		++sx[x].first;
		++sy[y].first;
		a.insert(make_pair(x, y));
	}
	sort(sx.rbegin(), sx.rend());
	sort(sy.rbegin(), sy.rend());
	int ret = 0;
	for (const auto& gx : sx) {
		for (const auto& gy : sy) {
			int d = a.count(make_pair(gx.second, gy.second));
			ret = max(ret, gx.first + gy.first - d);
			if (d == 0) {
				break;
			}
		}
	}
	cout << ret << endl;
	return;
	
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
}