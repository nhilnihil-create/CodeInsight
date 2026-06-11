/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI = 3.141592653589793;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	int b[n];
	int c[n-1];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int i=0;i<n-1;i++) cin >> c[i];
	int ans = 0, ind = -2;
	for(int i=0;i<n;i++)
	{
		int x = a[i];
		x--;
		ans += b[x];
		if(ind+1==x)
		{
			ans += c[ind];
		}
		ind = x;
	}
	cout << ans ;
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T=1;
	while(T--) solve();
	return 0;
}

