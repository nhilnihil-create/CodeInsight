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

vector<string> g;

int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n, m;
    cin >> n >> m;
    
    if (n % 2)
    {
        for (int i = 1; i <= m; ++i)
        {
            cout << i << " " << n + 1 - i << endl;
        }
    }
    else
    {
        for (int i = 1; i <= (m + 1) / 2; ++i)
        {
            cout << i << " " << n + 1 - i << endl;
        }
        for (int i = (m + 1) / 2 + 1; i <= m; ++i)
        {
            cout << i + 1 << " " << n + 1 - i << endl;
        }
        
    }
    

    return 0;
}