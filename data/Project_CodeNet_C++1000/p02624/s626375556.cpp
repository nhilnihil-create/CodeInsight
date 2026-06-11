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
vector<vector<bool>> used;
vector<ll> d;
 
int main() {
    
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n;
    cin >> n;

    ll ret = 0;

    for (ll i = 1; i <= n; ++i)
    {
        ll c = n / i;
        ret += ((i + i * c) * c)  / 2ll;
    }

    
    cout << ret << endl;
    
    return 0;
}