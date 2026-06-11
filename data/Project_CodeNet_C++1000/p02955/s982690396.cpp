#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g;
int n, m, k;
int a[N];
string ss;

int ch(int x)
{
	int reqd = 0;
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		int cur = a[i] % x;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	int l = 0, r = v.size() - 1;
	int rem = 0;
	while(l <= r)
	{
		if(rem <= 0)
		{
			rem += v[l];
			reqd += v[l];
			l++;
		}
		else
		{
			rem -= (x - v[r]);
			reqd += (x - v[r]);
			r--;
		}
	}
	if(reqd > 2 * k)
		return 0;
	if(rem != 0)
		return 0;
	return 1;
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	int mx = 0;
	for (int i = 1; i * i <= sum; i++){
		if(sum % i == 0 && ch(i)) mx = max(i, mx);
		if(sum % (sum / i) == 0 && ch(sum / i)) mx = max(sum / i, mx);
	}
	cout << mx;
	return 0;
}










