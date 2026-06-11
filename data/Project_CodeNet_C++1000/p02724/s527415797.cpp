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
    ll X;
    cin >> X;
    ll ans = 0;
    ll q = X / 500;
    ans += 1000 * q;
    X -= q * 500;
    if (X > 0)
    {
        ll y = X / 5;
        ans += 5 * y;
    }
    cout << ans << endl;
    return 0;
}
