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
    int k;
    cin >> k;
    int val = 7%k;
    for (int i = 1; i <= 3*k; ++i) {
        if(val == 0) {
            cout << i << "\n";
            return 0;
        }
        val = (val*10+7)%k;
    }
    cout << -1 << "\n";
    return 0;
}