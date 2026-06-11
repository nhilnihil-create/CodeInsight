//#pragma GCC optimize("Ofast")

#pragma GCC optimize("O3")
//#pragma GCC target("avx,avx2,fma")
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<set>
#include<vector>
#include<sstream>
#include<queue>
#include <iomanip>
#include<unordered_set>
#include <stack>
#include <unordered_map>
#include <map>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long int ul;
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i+=1)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i-=1)
#define endl '\n'
#define N 1000000007// prime modulo value 
#define C 1000000001
#define M 998244353
#define all(x) x.begin(),x.end()
using namespace std;
// From Geeksforgeeks
inline ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
// Power function took from geeksforgeeks
ll power(ll x, ll y)
{
	ll res = 1;

	x = x;
	if (x == 0) return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res;
}
double dist(ll x1, ll y1, ll x2, ll y2)
{
	double ans = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	unordered_map<ll, vector<ll>> mp;
	f(i, 0, n)
	{
		ll a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}
	ll ans = 0;
	priority_queue<ll> pq;
	f(i, 1, m + 1)
	{
		if (mp.find(i) != mp.end())
		{
			f(j, 0, mp[i].size())
				pq.push(mp[i][j]);
		}
		if (pq.empty() == false)
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}
