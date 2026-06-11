// 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ac = a * c;
    ll bc = b * c;
    ll ad = a * d;
    ll bd = b * d;

    ll m1 = max(ac, bc);
    ll m2 = max(ad, bd);
    ll ans = max(m1, m2);
    
    cout << ans << endl;
    return 0;
}
