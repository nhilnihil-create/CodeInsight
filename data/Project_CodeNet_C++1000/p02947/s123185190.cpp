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
	vector <string> s(n);
	for(int i=0;i<n;i++)
	{
		string x;
		cin >> x;
		sort(all(x));
		s[i] = x;
	}
	sort (all(s));
	int i=0,j=0;
	int ans = 0;
	for(i=0;i<n;)
	{
		string cur = s[i];
		for(j=i+1;j<n;j++)
		{
			if(s[j]!=cur) break;
		}
		int f = (j-i);
		ans += f*(f-1);
		i = j;
	}
	cout << ans/2 ;
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

