#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n;
// string s;

int main() {
    cin >> n;

    V<Pll> v(n);
    REP(i, n) {
        ll d, c; cin >> d >> c;
        v[i] = {d, c};
    }

    ll digit = 0, sum = 0;
    for (auto x: v) {
        digit += x.second;
        sum += x.first * x.second;
    }

    std::cout << digit - 1 + (sum - 1) / 9 << '\n';

    return 0;
}
