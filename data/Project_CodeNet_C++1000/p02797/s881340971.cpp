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

long long gcd(const long long& a, const long long& b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, k, s;
    cin >> n >> k >> s;
    
    for (int i = 0; i < n; ++i)
    {
        if (i < k)
        {
            cout << s;
        }
        else
        {
            if (s == 1000000000ll)
            {
                cout << 1;
            }
            else
            {
                cout << 1000000000ll;
            }
        }
        
        if (i != n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}