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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ng = 0, ok = INF<int>;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        ll val = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] >= mid+1){
                val += (v[i]-1)/mid;
            }
        }
        if(val <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}