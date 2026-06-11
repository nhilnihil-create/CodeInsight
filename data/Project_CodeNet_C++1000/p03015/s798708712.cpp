#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll MOD = 1000000007;
    vector<ll> p2(100001);
    vector<ll> p3(100001);
    ll b2 = 1;
    ll b3 = 1;
    rep(i, 100001) {
        p2[i] = b2;
        p3[i] = b3;
        b2 *= 2;
        b3 *= 3;
        b2 %= MOD;
        b3 %= MOD;
    }
    string s;
    cin >> s;
    ll res = 0;
    int c1 = 0;
    rep(i, s.size()) {
        if (s[i] == '1') {
            res += p2[c1] * p3[s.size() - (1 + i)];
            res %= MOD;
            c1++;
        }
    }
    res += p2[c1];
    res %= MOD;
    cout << res << endl;
    return 0;
}

