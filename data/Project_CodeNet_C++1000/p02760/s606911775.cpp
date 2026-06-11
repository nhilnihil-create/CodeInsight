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
#define vi std::vector<int>
#define pi std::pair<int, int>
#define mp std::make_pair
#define stdabs std::abs
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
#define vec std::vector
#define oreq |=
#define npm next_permutation
#define Yes std::cout << "Yes" << std::endl
#define No std::cout << "No" << std::endl
#define YES std::cout << "YES" << std::endl
#define NO std::cout << "NO" << std::endl
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
ll extgcd(ll a, ll b, ll& x, ll& y);
ll nCr(ll n, ll r);
void stat();
template <typename T> T fact(T num);
unsigned long long modpow(int x__, int n__, long long mod__);
template <typename T> void debug(const T& t);
constexpr ll mod10_9p7 = 1000000000 + 7;

/**************************************************************/
int main()
{
    stat();
    int n;
    vec<vec<int>> bin(3, vec<int>(3));
    rep(i, 3)
    {
        rep(j, 3) { cin >> bin[i][j]; }
    }
    cin >> n;
    vec<int> b(n);
    rep(i, n) { cin >> b[i]; }
    auto find = [&bin](int x) {
        rep(i, 3)
        {
            rep(j, 3)
            {
                if (bin[i][j] == x) { bin[i][j] = -1; }
            }
        }
    };
   rep(i,n) {find(b[i]);}
    rep(i, 3)
    {
        if (bin[i][0] == bin[i][1] && bin[i][2] == bin[i][1] && bin[i][0] == -1) {
            Yes;
            return 0;
        }

	if(bin[0][i]==bin[1][i]&&bin[2][i]==bin[1][i]&&bin[0][i]==-1){Yes;return 0;}
    }
if(bin[0][0]==bin[1][1]&&bin[1][1]==bin[2][2]&&bin[0][0]==-1){Yes;return 0;}

if(bin[0][2]==bin[1][1]&&bin[1][1]==bin[2][0]&&bin[0][2]==-1){Yes;return 0;}
No;
    return 0;
}
/**************************************************************/
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

unsigned long long modpow(int x__, int n__, long long mod__)
{
    long long ret__ = 1;
    for (long long i__ = 0; i__ < n__; ++i__) {
        ret__ = ret__ * x__ % mod__;
    }
    return ret__;
}

template <typename T> void debug(const T& t)
{
#ifdef local
    dbg(t);
#endif
}
