#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const long long mod = 1e9 + 7;

int main() {
    
    
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    ll ma = v[n - 1];
    ll mi = v[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (v[i] > 0)
        {
            mi -= v[i];
        }
        else
        {
            ma -= v[i];
        }
    }
    
    ll ret = ma - mi;
    
    cout << ret << endl;
    ma = v[n - 1];
    mi = v[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (v[i] > 0)
        {
            cout << mi << " " << v[i] << endl;
            mi -= v[i];
        }
        else
        {
            cout << ma << " " << v[i] << endl;
            ma -= v[i];
        }
    }
    
    cout << ma << " " << mi << endl;
    
    return 0;
}