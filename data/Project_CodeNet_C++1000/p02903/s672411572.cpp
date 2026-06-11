#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ff(i, c, n) for (ll i = c; i < n; i++)
#define fr(i, c, n) for (ll i = c; i >= n; --i)
#define INF 1e9 + 7

ll modpow(ll a, ll b, ll c)
{ //a^b%c in O(logb)
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * a) % c;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	return res;
}
ll modinv(ll m, ll n)
{ //modular inverse of n w.r.t m provided 1<=n<=(m-1) in O(logn) and m is prime
	ll inv[n + 1];
	inv[1] = 1;
	for (int i = 2; i < n + 1; ++i)
		inv[i] = (m - (m / i) * inv[m % i] % m) % m;
	return inv[n];
}

//a+b=a^b+2*(a&b)
int main()
{
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	ff(i,0,h){
		if(i<b){
			ff(j,0,w){
				if(j<a) cout<<'1';
				else cout<<'0';
			}
		}
		else{
			ff(j,0,w){
				if(j<a) cout<<'0';
				else cout<<'1';
			}
		}
		cout<<endl;
	}
	


	return 0;
}
