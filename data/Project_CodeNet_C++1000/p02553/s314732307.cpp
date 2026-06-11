/*
* @Author: Nazrul Islam
* @Date:   2020-09-19 12:28:42
* @Last Modified by:   Nazrul Islam
* @Last Modified time: 2020-09-19 12:29:57
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
void solve()
{
	ll n, m, i, j, k, l;
	ll  a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(a*c, max(a*d, max(b*c, b*d))) << endl; 
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