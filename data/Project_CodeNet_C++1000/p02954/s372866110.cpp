#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
#include <utility>
#include <queue>
#include <numeric>
#include <time.h>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;
const dd PI = 3.1415926435;

class UnionFind
{
public:
    UnionFind(int N) : par(N)
    {
        for (ll i = 0; i < N; i++)
        {
            par[i] = i;
        }
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

private:
    vector<int> par;
};

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

ll fact(ll n)
{
    if (n <= 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

ll pow_fast(ll n, ll k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }

    if (k % 2 == 0)
    {
        ll tmp = pow_fast(n, k / 2LL);
        return tmp * tmp % MOD;
    }
    else
    {
        ll tmp = pow_fast(n, k / 2LL);
        tmp *= tmp;
        tmp %= MOD;
        return tmp * n % MOD;
    }
}

map<ll, ll> sosuu(ll n)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i] += 1;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n] += 1;
    }
    return res;
}

struct Dish
{
    ll time;
    ll taste;
};

static ll FACTORIAL[10000010] = {};
ll nCk(ll n, ll k)
{
    if (FACTORIAL[1] == 0)
    {
        FACTORIAL[0] = 1;
        FACTORIAL[1] = 1;
        for (ll i = 2; i <= 10000000; i++)
        {
            FACTORIAL[i] = FACTORIAL[i - 1] * i;
            FACTORIAL[i] %= MOD;
        }
    }
    ll N_fact = FACTORIAL[n];
    ll K_fact = pow_fast(FACTORIAL[k], MOD - 2);
    ll N_K_fact = pow_fast(FACTORIAL[n - k], MOD - 2);
    ll ret = N_fact;
    ret %= MOD;
    ret *= K_fact;
    ret %= MOD;
    ret *= N_K_fact;
    ret %= MOD;
    return ret;
}

void solve(string s, ll K)
{
    ll sum = 0;
    for (ll i = s.size(); i <= s.size() + K; i++)
    {
        // 25
        ll cnt = pow_fast(25, i - s.size()) % MOD;
        cnt *= nCk(i - 1, s.size() - 1);
        cnt %= MOD;

        // 26
        cnt *= pow_fast(26, s.size() + K - i);
        cnt %= MOD;

        sum += cnt;
        sum %= MOD;
    }
    cout << sum << endl;
    return;
}

vector<string> explode(string s, char delim)
{
    vector<string> ret;
    string cur;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == delim)
        {
            ret.push_back(cur);
            cur.clear();
            continue;
        }
        cur += s[i];
    }

    if (cur.size() != 0)
    {
        ret.push_back(cur);
    }

    return ret;
}

template <typename T>
void DEBUG(T var)
{
    static size_t cnt = 1;
    cout << "[DEBUG] " << cnt << " :";
    cout << "(" << typeid(var).name() << ")";
    cout << var << endl;
    cnt += 1;
}

struct Element
{
    char c;
    bool visited;
    ll cost;
};

vector<vector<ll>> comb(ll n)
{
    vector<vector<ll>> ans(n + 1, vector<ll>(n + 1));

    ans[0][0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                ans[i][j] = 1;
                continue;
            }
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }

    return ans;
}

ll solve(vector<ll> H, vector<ll> cur)
{
    ll mid = -1;
    bool same = true;
    for (ll i = 0; i < cur.size(); i++)
    {
        if (H[i] != cur[i])
        {
            same = false;
        }
    }
    if (same)
    {
        return 0;
    }

    for (ll i = 0; i < cur.size(); i++)
    {
        if (H[i] == cur[i])
        {
            mid = i;
            break;
        }
    }

    if (mid == -1)
    {
        for (ll i = 0; i < cur.size(); i++)
        {
            cur[i] += 1;
        }
        return solve(H, cur) + 1;
    }

    vector<ll> front;
    vector<ll> H_front;
    for (ll i = 0; i < cur.size(); i++)
    {
        if (i < mid)
        {
            front.push_back(cur[i]);
            H_front.push_back(H[i]);
        }
    }

    vector<ll> back;
    vector<ll> H_back;
    for (ll i = 0; i < cur.size(); i++)
    {
        if (i > mid)
        {
            back.push_back(cur[i]);
            H_back.push_back(H[i]);
        }
    }
    return solve(H_front, front) + solve(H_back, back);
}

int main()
{
    string S;
    cin >> S;

    vector<ll> last(S.size());

    for (ll i = 0; i < S.size(); i++)
    {
        if (S[i] == 'R') {
            ll r = i + 1;
            while (S[r] == 'R')
            {
                r += 1;
            }
            last[i] = r;
        } else {
            ll l = i - 1;
            while (S[l] == 'L') {
                l -= 1;
            }
            last[i] = l;
        }
    }
    vector<ll> ans(S.size());
    for (ll i = 0; i < S.size(); i++)
    {
        if (S[i] == 'R') {
            if ((last[i] - i) % 2 == 0) {
                ans[last[i]] += 1;
            } else {
                ans[last[i] - 1] += 1;
            }
        } else {
            if ((last[i] - i) % 2 == 0) {
                ans[last[i]] += 1;
            } else {
                ans[last[i] + 1] += 1;
            }
        }
    }
    for (ll i = 0; i < S.size(); i++)
    {
        cout << ans[i] << endl;
    }
        

    return 0;



    ll N;
    cin >> N;

    dd weight = 0;
    vector<pair<dd, dd>> T(1001, {-1, -1});

    for (ll i = 0; i < N; i++)
    {
        ll xi, yi, ci;
        cin >> xi >> yi >> ci;

        if (T[ci].first == -1 && T[ci].second == -1) {
            T[ci] = {xi, yi};
            continue;
        }
        T[ci].first += xi;
        T[ci].second += yi;

        T[ci].first /= 2;
        T[ci].second /= 2;
    }

    ll c = 0;
    ll x = 0;
    ll y = 0;
    for (ll i = 1; i <= 1000; i++)
    {
        if (T[i].first == -1 && T[i].second == -1) {
            continue;
        }
        if (c == 0){ 
            c = i;
            x = T[i].first;
            y = T[i].second;
            continue;
        }
        x = (x * i + T[i].first * c) / (i + c);
        y = (y * i + T[i].second * c) / (i + c);
        c = (i + c);
    }
    cout << x << "," << y << "," << c << endl;
}