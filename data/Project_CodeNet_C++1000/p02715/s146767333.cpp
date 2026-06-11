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

vector<string> g;

long long mpow(const long long &v, const long long &n, const long long &mod)
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


int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    
    
    vector<ll> r(k + 1, -1);
    
    for (ll i = k; i >= 1; --i)
    {
        ll count = mpow(k / i, n, mod);
        for (ll j = 2 * i; j <= k; j += i)
        {
            count -= r[j];
            if (count < 0)
            {
                count += mod;
            }
        }
        r[i] = count;
    }
    
    ll ret = 0;
    for (int i = 1; i <= k; ++i)
    {
        ret += i * r[i];
        ret %= mod;
    }
    
    cout << ret << endl;
    

    return 0;
}

