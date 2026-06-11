#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<stack>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
const double PI = acos(-1);  // PI = 3.141593...

int ceil(int a, int b) {
    return (a+b-1) / b;
}

int main() {
    int k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];

    ll n, x, m;
    ll last, count_equal, count_di;
    rep(i, q) {
        cin >> n >> x >> m;
        last = x;
        count_equal = 0;
        rep(j, k) {
            count_di = ceil(n-1-j, k);
            last += (d[j] % m) * count_di;
            if(d[j] % m == 0) count_equal += count_di;
        }
        cout << (n-1) - (last/m - x/m) - count_equal << endl;
    }

    return 0;
}