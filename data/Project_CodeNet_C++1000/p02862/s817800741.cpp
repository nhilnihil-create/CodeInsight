#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<vector<ll>> g;
vector<ll> fac;
vector<ll> inv;

long long ppow(const long long &v, const long long &n, const long long &mod)
{
    long long ret = 1;
    long long num = n;
    long long now = v;
    
    while (num > 0)
    {
        if (num & 1)
        {
            ret = ret * now % mod;
        }
        now = now * now % mod;
        num = num >> 1;
    }
    
    return ret;
}


long long calc(const long long &n, const long long &k, const long long &mod)
{
    long long ret;
    fac = vector<long long>(n + 1, 1);
    inv = vector<long long>(n + 1, 1);
    
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = ppow(fac[i], mod - 2, mod);
    }
    
    ret = fac[n] * inv[k] % mod * inv[n - k] % mod;
    
    return ret;
}

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll x, y;
    cin >> x >> y;
    
    if ((x + y) % 3 != 0 || (x > 2 * y || y > 2 * x))
    {
        cout << 0 << endl;
        return 0;
    }
    
    ll c = (x + y) / 3;
    ll cc = min(x, y) - c;
    cout << calc(c, cc, mod) << endl;
    
    return 0;
}