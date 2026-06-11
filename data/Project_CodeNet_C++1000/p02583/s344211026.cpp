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

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(v[i] == v[j]) continue;
            for (int k = j+1; k < n; ++k) {
                if(v[i] == v[k] || v[j] == v[k]) continue;
                if(2*max({v[i], v[j], v[k]}) < v[i]+v[j]+v[k]) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}