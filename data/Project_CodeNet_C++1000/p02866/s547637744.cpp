#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long
#define F first
#define S second
#define ld long double
#define fa fflush(stdout); 
#define mp make_pair
using namespace std;
void data() {
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
} 
const int N = 1e6 + 100;
const ll mod = 998244353;
const ll mod2 = 1e9 + 7;
 
ll mul(ll a, ll b) {
	return (a * b) % mod;
}
ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
		res %= mod;
		a %= mod;
	}
	return res;
}
ll kol[N];
int main () 
{
    data();      
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		kol[a[i]]++;
	}
	if (kol[0] != 1 || a[1])
	{
		cout << 0;
		return 0;
	}
	while (kol[n] == 0)
	{
		n--;
	}
	ll ans = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= kol[i + 1]; j++)
		{
			ans = mul(ans, kol[i]);
		}	
	//	cout << ans << '\n';
	}
	cout << ans;
}
//Timus:295965SY              