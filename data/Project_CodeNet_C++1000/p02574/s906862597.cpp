#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
#define FOR(i, s, n) for (ll i = (s); i < (n); ++i)
#define FORALL(i, n) for (ll i = 0; i < (n); ++i)
#define MOD 1000000007
#define ff first
#define ss second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(false)
#define countbits(x) __builtin_popcount(x)
#define pb(x) push_back((x))
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define print(x) cout << x << endl
#define debug print("reaching\n")
#define mll map<ll,ll>
#define lsb(i) i&(-i)
#define printv(x) \
	FORALL(i, x.size()) \
	{ \
		cout << x[i] << ' '; \
	} \
	cout << endl \
;
#define printm(m) \
	for(auto i: m){\
		cout<<i.ff<<' '<<i.ss<<endl; \
	}\
;
// vector<map<ll,ll>> m(2);
long long binpow(long long a, long long b) {
	if(b<=0) return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



template <typename T>
T extGcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m)
{
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

void Linearsieve(ll n, vll& primes)
{
    vector<bool> v(n + 1, true);
    for (ll i = 2; i <= n; i++)
    {
        if (v[i])
        {
            primes.pb(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; j++)
        {

            v[i * primes[j]] = false;

            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
}


int main()
{
	fast;
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t=1;
	// cin>>t;
	ll tot=t;
	while(t--){
		ll n;
		cin>>n;
		vll v(n);
		ll maxo = 0;
		FORALL(i,n){
			cin>>v[i];
		}
		unordered_map<ll, ll> m;
		int p = 1;
		ll temp = v[0];
		FORALL(i,n){
			temp = __gcd(temp, v[i]);
		}
		FORALL(i, n){
			if(v[i] == 1) continue;
			for(int j = 2; j <= sqrt(v[i]); j++){
				if(v[i]%j==0){
					m[j]++;
					if(m[j]>1){
						p = 0;
						break;
					}
					while(v[i]%j==0){
						v[i]/=j;
					}
				}
			}
			if(v[i]!=1){
				m[v[i]]++;
				if(m[v[i]]>1){
					p = 0;
					break;
				}
			}
			if(p==0) break;
		}

		if(p){
			print("pairwise coprime");
		}
		else if(temp==1){
			print("setwise coprime");
		}
		else{
			print("not coprime");
		}
	}
	return 0;
}
