#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];
#define forr(a,b) for(ll i=a;i<b;i++);
ll gcd(ll x, ll y)
{
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}
// 1or素数だと１を返す
ll prime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}



int main()
{
	ll n, m;
	cin >> n >> m;
	
	priority_queue<ll> a;
	ll p;
	for(ll i=0;i<n;i++)
	{
		cin >> p;
		a.push(p);
	}
  
	ll q;
	for(ll i=0;i<m;i++)
	{
		q = a.top();
		a.pop();
		q /= 2;
		a.push(q);
	}
	ll ans = 0;
	for(ll i=0;i<n;i++)
	{
		ans += a.top();
		a.pop();
	}

	cout << ans << "\n";

	return 0;
}