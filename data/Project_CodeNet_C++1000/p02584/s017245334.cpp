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
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll a = x/d;
    if(a > k){
        cout << x-k*d << "\n";
    }else {
        if((k-a)&1) cout << abs(x-(a+1)*d) << "\n";
        else cout << abs(x-a*d) << "\n";
    }
    return 0;
}