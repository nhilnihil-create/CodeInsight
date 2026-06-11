#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repab(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define  printarr(v) for(auto x:v){cout<<x<<" "; }
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
void solve()
{
	ll n;
	cin >> n;
	vector<vector<ll>> v(4, vector<ll>(n));
	rep(i, n)
	{
		ll x, y;
		cin >> x >> y;
		v[0][i] = (x - y);
		v[1][i] = (x + y);
		v[2][i] = (-x + y);
		v[3][i] = (-x - y);
	}
	for (int i = 0; i < 4; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	ll res = LLONG_MIN;
	for (int i = 0; i < 4; i++)
	{
		res = max(res, v[i][n - 1] - v[i][0]);
	}
	cout << res << endl;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();

	}
}
