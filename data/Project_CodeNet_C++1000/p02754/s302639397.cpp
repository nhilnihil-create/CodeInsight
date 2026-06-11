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

#define debug(x) cout << __LINE__ << " " << #x <<"..." << x << endl
#define dev(x) cout << __LINE__ << " " << #x << "..." ; for(auto &it : x) cout<< it << " "; cout << endl;

const double PI = 3.141592653589793;

void solve()
{
	int n,a,b;
	cin >> n >> a >> b;
	if(a==0)
	{
		cout << "0\n";
		return ;
	}
	int x = n /(a+b);
	int ans = 0;
	ans += x * a;
	ans += min(a,n%(a+b));
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

