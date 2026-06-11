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

#define debug(x,i,j) cout << #x << " " << #i << " " << #j << " " << x << " "<< i << " " << j<< endl

const double PI = 3.141592653589793;

void solve()
{
	int l,r;
	cin >> l >> r;
	if(r-l>=2019)
	{
		cout << "0";
		return ;
	}
	int ans = 2020 ;
	for(int i=l;i<r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			ans = min(ans, (i*j)%2019);
		}
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

