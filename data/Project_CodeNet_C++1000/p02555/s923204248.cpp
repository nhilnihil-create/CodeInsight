/*
* @Author: Nazrul Islam
* @Date:   2020-09-21 00:43:11
* @Last Modified by:   Nazrul Islam
* @Last Modified time: 2020-09-21 00:56:42
*/

#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll; 
typedef double dd;
typedef vector<int> vi;
typedef vector<char> vc;
typedef list<int> li;
typedef set<int> si;
typedef map<int,int> mp;
#define pb push_back
#define pf push_front
#define mk make_pair
#define sc scanf
#define pr printf
#define pi acos(-1.0)
#define endl '\n'
// char s[200009];
// char st[200009];
// int a[600][600];
// int b[29][10];
// int a[200009];
// int c[200009];
ll dp[2003];
ll m = 1e9+7;

ll mod(ll n) {
	return ((n%m + m)%m);
}

ll add(ll a, ll b) {
	return mod(mod(a) + mod(b));
}

ll result(ll n) {
	if(n == 0) return 1;
	else if(n < 3) return 0;
	else if(n >= 3 && n < 6) return 1;
	else if(dp[n] != -1) return dp[n];
	else {
		ll p = 0;
		for (int i = 3; i <= n; i++) {
			if(n-i >= 0)
				p = add(p, result(n-i));
		}
		
		return dp[n] = p;
	}
}

void solve()
{
	ll n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	ll q = result(n);
	cout << q%m << endl; 
}
int main()
{
	IO;
	int t; 
	t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}