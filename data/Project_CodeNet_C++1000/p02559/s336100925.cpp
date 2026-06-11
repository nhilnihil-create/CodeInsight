//配列の総和
#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
    cout << a << endl;
    exit(0);
}

void Main(void)
{
    ll n, q; cin >> n >> q;
    fenwick_tree<ll> x(n);
    rep(i, n)
    {
        ll a;
        cin >> a;
        x.add(i, a);
    }
    rep(i, q)
    {
        ll a, b, c; cin >> a >> b >> c;
        if(a) cout << x.sum(b, c) << endl;
        else x.add(b, c);
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12); //高精度少数表示
    Main();
    return 0;
}