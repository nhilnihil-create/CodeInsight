// JAI SHREE RAM
#pragma GCC optimize("O3")
typedef long long int ll;
typedef unsigned long long int ull;
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sec second
#define fir first
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define repe(i,m,n) for(ll (i)=(m);(i)<(n);(i)++)
// #define all(a) (a).begin(),(a).end()
#define pb push_back
#define pii pair<int,int>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define MOD 998244353
int n, k, c;
set<ll>st;
std::vector<ll> a,b;
void cnt(string x)
{

	int g = 0;
	for (int i = 0; i < n && g<k ; i++ )
	{
		if (x[i] == 'o')
		{
			g++;
			a.pb(i);
			i += c ;
		}

	}
	g = 0;
	for (int i = n - 1; i >= 0 && g<k ; i-- )
	{
		if (x[i] == 'o')
		{
			g++;
			b.pb(i);
			i -= (c);
		}

	}

	// for (auto el : st)
	// 	cout << el << endl;


	for(int i=0;i<k;i++)
	{
		if(a[i]==b[k-1-i])
			cout<<a[i]+1<<endl;
	}
	return ;
}
void solve()
{
	string s;
	cin >> n >> k >> c;
	cin >> s;
	cnt(s);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast
	int T;
	// cin >> T;
	T = 1;
	while (T--)
	{
		solve();
	}
	return 0;
}
