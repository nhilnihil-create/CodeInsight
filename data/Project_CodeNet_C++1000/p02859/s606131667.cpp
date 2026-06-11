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
	ll r;
	cin >> r;
	ll val = (22 / 7) * 1;
	ll val2 = (22 / 7) * (r * r);
	cout << val2 / val << endl;
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