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

#define debug(x) cout << __LINE__ << " : "#x << "..." << x << endl

const double PI = 3.141592653589793;

void solve()
{
	int n;
	cin >> n;
	vector <int> p(n);
	for(int i=0;i<n;i++) p[i] = i+1;
	vector <int> q(p);
	int a = 0, b = 0;
	vector <int> x(n);
	for(int &i : x) cin >> i;
	while(p!=x)
	{
		a++;
		next_permutation(all(p));
	}
	for (int &i : x) cin >> i;
	while(q!=x)
	{
		b++;
		next_permutation(all(q));
	}
	cout << abs(a-b);
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

