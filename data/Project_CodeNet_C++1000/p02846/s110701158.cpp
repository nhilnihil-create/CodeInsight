#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <assert.h>
#include <numeric>
#include <math.h>
#include <climits>
#include <stack>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename T>
inline bool sign(T A) {
    return (A>0)-(A<0);
}
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SREP(i,s,n) for(int i=s; (n-i)*sign(n-s)>0; i+=sign(n-s))
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

bool _less(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

template <template<class,class,class...> class C, typename K, typename V, typename... Args>
V map_get(const C<K,V,Args...>& m, K const& key, const V & defval)
{
    typename C<K,V,Args...>::const_iterator it = m.find( key );
    if (it == m.end())
        return defval;
    return it->second;
}

#define MOD (1'000'000'000 + 7)



int main(void)
{
    ll T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    if (A1*T1+A2*T2 > B1*T1+B2*T2) {
        swap(A1, B1);
        swap(A2, B2);
    }
    ll C1 = B1 - A1;
    ll C2 = B2 - A2;
    if (C1 == 0 || C1 * T1 + C2 * T2 == 0)
    {
        cout << "infinity" << endl;
    }
    else if (C1 > 0)
    {
        cout << 0 << endl;
    }
    else  {
        ll d = -C1 * T1;
        ll u = C1 * T1 + C2 * T2;
        cout << 2 + 2 * (d / u) - 1 - int(d%u == 0)<< endl;
    }

}
