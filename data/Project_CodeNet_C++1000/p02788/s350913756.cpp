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

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, d, a;
    cin >> n >> d >> a;
    
    vector<P> m(n);
    vector<ll> c(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i].first >> m[i].second;
    }
    
    sort(m.begin(), m.end());
    
    ll ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            c[i] += c[i - 1];
        }
        ll cur = m[i].second + c[i];
        if (cur > 0)
        {
            ll use = (cur + a - 1) / a;
            ret += use;
            c[i] -= use * a;
            auto itr = upper_bound(m.begin() + i, m.end(), P(m[i].first + 2ll * d, mod));
            c[itr - m.begin()] += use * a;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}