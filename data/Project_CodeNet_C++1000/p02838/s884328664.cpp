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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> num(60, 0);
    REP(i, n){
        cin >> a[i];
        REP(j, 60){
            num[j] += (a[i]>>j)&1;
        }
    }
    ll ans = 0;
    ll p = 1;
    REP(i, 60){
        ans = (ans + (num[i]*(n-num[i]))%MOD*p) % MOD;
        p = (p * 2) % MOD;
    }


    cout << ans << endl;
    return 0;
}