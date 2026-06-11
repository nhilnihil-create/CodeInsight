#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

using namespace __gnu_pbds;
using namespace std;

// MACROS

#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define u_s unordered_set

#define pii pair<int,int>
#define pll pair<ll,ll>

#define FOR(i, n) for (ll i = 0; i < n; i++)
#define FORN(i, a, b) for (ll i = a; i < b; i++)
#define FORE(i, l) for (auto i : l)

#define pb push_back
#define pob pop_back
#define emp emplace
#define fi first
#define se second

#define all(n) n.begin(), n.end()
#define in(n) cin >> (n);
#define debug(n) cout << #n << ": " << n << '\n';

// FUNCTIONS

template< typename T >
inline T gcd(T a, T b) { if (b) return gcd(b, a % b); return a; }

template< typename T >
inline T ext_gcd(T a, T b, T & x, T & y) { if (a == 0) { x = 0; y = 1; return b; } T x1, y1; T g = ext_gcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return g; }

bool check(ll x, ll f)
{
    while (x % f == 0) x /= f;
    return x % f == 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);	
    //cout << setprecision(15);
    ll n;
    cin >> n;
    set<ll> s;
    for (ll i = 2; i * i <= n; i++)
    {
        if (check(n, i)) s.emp(i);
        if ((n - 1) % i == 0)
        {
            s.emp(i);
            s.emp((n - 1) / i);
        }
    }
    s.emp(n); if (n > 2) s.emp(n - 1);
    cout << s.size() << '\n';
}

