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


int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    cin >> s;
    
    vector<bool> dp1(s.size());
    vector<bool> dp2(s.size());
    dp1[a] = 1;
    dp2[b] = 1;
    
    for (int i = b + 1; i <= d; ++i)
    {
        if (s[i] == '.')
        {
            if (i - 2 >= 0)
            {
                dp2[i] = max(dp2[i], dp2[i - 2]);
            }
            if (i - 1 >= 0)
            {
                dp2[i] = max(dp2[i], dp2[i - 1]);
            }
        }
    }
    bool f = 0;
    for (int i = a + 1; i <= c; ++i)
    {
        if (s[i] == '.')
        {
            if (i - 2 >= 0)
            {
                dp1[i] = max(dp1[i], dp1[i - 2]);
            }
            if (i - 1 >= 0)
            {
                dp1[i] = max(dp1[i], dp1[i - 1]);
            }
            if (d < c)
            {
                if (i > b && i - 2 >= 0 && i <= d + 1)
                {
                    if (dp1[i] && dp1[i - 1] && dp1[i - 2])
                    {
                        f = 1;
                    }
                }
            }
            else
            {
                f = 1;
            }
        }
    }
    
    if (dp1[c] && dp2[d] && f)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    
    return 0;
}