#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
//#define local
#ifdef local
#include "dbg-macro/dbg.h"
#endif
//#define hacks
#ifdef hacks
#include <boost/multiprecision/cpp_int.hpp>
#endif

#define p std::pair
#define ll long long
#define ull unsigned long long
#define pi (acos(-1))
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
constexpr ll mod = 1000000000 + 7;

int main()
{
    int n, d;
    cin >> n >> d;
    vec<vec<int>> r(n, vector<int>(d));

    rep(i, n)
    {
        rep(j, d) { cin >> r[i][j]; }
    }

    ll ans = 0;
    rep(i, n)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sq = 0;
            rep(k, d)
            {
                int sub = r[i][k] - r[j][k];
                sq += sub * sub;
            }
	    double dist=sqrt(sq);
	    if(dist==floor(dist)){++ans;}
        }
    }
cout<<ans<<endl;
    return 0;
}
ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
            P.emplace_back(i);
        }
    }
    return P;
}

