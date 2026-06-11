#include <bits/stdc++.h>
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
#define ld long double
#define ull unsigned long long
#define pi std::pair<int, int>
#define mp std::make_pair
#define stdabs std::abs
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
#define oreq |=
#define npm next_permutation
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
ll extgcd(ll a, ll b, ll& x, ll& y);
ll nCr(ll n, ll r);
void stat();
template <typename T> T fact(T num);
constexpr ll mod = 1000000000 + 7;
int main()
{
    stat();
    unordered_map<string, int> map;

    int n;
    cin >> n;
    string s;
    rep(i, n)
    {
        cin >> s;
        if (map.count(s) == 0) { map.insert(mp(s, 0)); }
        else {
		 ++map.at(s);
		

        }

    }
    vec<string> ans;
    int maxc = 0;
    for (auto const& st : map) {
        maxc = max(maxc, st.second);
    }
#ifdef local
    dbg(maxc);
#endif
    for (auto const& st : map) {
        if (st.second == maxc) { ans.push_back(st.first); }
    }
    sort(all(ans));
    for (const auto& a : ans) {
        cout << a << endl;
    }
    return 0;
}
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
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
    for (unsigned ll i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (unsigned ll j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}

void stat(){
#ifdef local
    rep(i, 2){std::cout << "local enable" << std::endl;
}
#endif
#ifdef hacks
rep(i, 2) { std::cout << "boost enable" << std::endl; }
#endif
}

ll nCr(ll n, ll r)
{
    ll num = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

template <typename T> T fact(T num)
{
    if (num == 1) { return 1; }
    return num * fact(num - 1);
}
