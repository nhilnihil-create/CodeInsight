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
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;
const ll mmod = 998244353;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<string> g;
vector<vector<ll>> dp;

int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    
    ll ret = 0;
    if (p == 2 || p == 5)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((s[i] - '0') % p == 0)
            {
                ret += (i + 1ll);
            }
        }
    }
    else
    {
        map<ll, ll> m;
        ll c = 1;
        ll now = 0;
        m[0]++;
        for (int i = n - 1; i >= 0; --i)
        {
            now += (s[i] - '0') * c;
            now %= p;
            c *= 10;
            c %= p;
            ret += m[now % p];
            m[now % p]++;
        }
        
    }
    
    cout << ret << endl;
    
    return 0;
}