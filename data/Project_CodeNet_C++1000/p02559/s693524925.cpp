#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
template<class T>
class BIT {
    vector<T> bit;
    int n, m;
public:
    BIT(int n): n(n), bit(n){
        m = 1;
        while(m < n) m <<= 1;
    }

    T sum(int k){
        T ret = 0;
        for (; k > 0; k -= (k & -k)) ret += bit[k-1];
        return ret;
    }

    void add(int k, T x){
        for (k++; k <= bit.size(); k  += (k & -k)) bit[k-1] += x;
    }

    T lower_bound(T x){
        int i = -1;
        for (int j = m; j; j >>= 1) {
            if(i+j < bit.size() && bit[i+j] < x) x -= bit[i += j];
        }
        return i;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    BIT<ll> S(n);
    for (int i = 0; i < n; ++i) S.add(i, v[i]);

    for (int i = 0; i < q; ++i) {
        int c, x, y;
        scanf("%d %d %d", &c, &x, &y);
        if(c == 0) S.add(x, y);
        else printf("%lld\n", S.sum(y) - S.sum(x));
    }
    return 0;
}