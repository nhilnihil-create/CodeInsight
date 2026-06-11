#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = 1e9 + 7;

int power(int n, int p)
{
    if (p == 0)
        return 1;
    long long res = 1;
    long long add = n;
    while (p > 0)
    {
        if (p & 1)
            res = (res * add) % MOD;
        p >>= 1;
        add = add*add%MOD;
    }
    return res;
}

      
int getinv(int n) {
    static int invtable[200001];
    if (invtable[n])
        return invtable[n];
    return invtable[n] = power(n, MOD - 2);
}

int comb(int n, int r) {
    long long res = 1;
    for (int i = n - r + 1; i <= n; i++)
        res = (res * i) % MOD;
    for (int i = 1; i <= r; i++)
        res = (res * getinv(i)) % MOD;

    return res;
}
      

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = power(2, n) - 1;

    ans = (ans + MOD - comb(n, a)) % MOD;
    ans = (ans + MOD - comb(n, b)) % MOD;

    cout << ans << endl;
    return 0;
}