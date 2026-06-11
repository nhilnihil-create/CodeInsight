/*
* @Author: Nazrul Islam
* @Date:   2020-09-20 20:15:13
* @Last Modified by:   Nazrul Islam
* @Last Modified time: 2020-09-20 21:06:57
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
ll m = 1e9+7;
ll func(ll n, ll k) {
	// cn++;
	if(k == 0) return 1;
	ll p = func(n, k/2);
	if(k % 2 == 0) return ((p * p) % m);
	else return (((p*p)%m*n) %m);
}
void solve()
{
	ll n;
	cin >> n;
	// if(n == 0) cout << ""
	ll o = func(10, n) - 2*func(9, n) + func(8, n);
	o = o%m;
	o = (o+m)%m;
	cout << o << endl; 
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