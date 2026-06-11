#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
void solve()
{
	map<ll, ll> m;
	m[1]++;
	m[2]++;
	m[3]++;
	ll a, b;
	cin >> a >> b;
	m[a]++;
	m[b]++;
	for (auto x : m)
	{
		if (x.second == 1)
		{
			cout << x.first << endl;
			return;
		}
	}

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