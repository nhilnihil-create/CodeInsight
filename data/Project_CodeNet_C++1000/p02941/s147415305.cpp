#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <bitset>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n, i_prev, i_next;
    cin >> n;
    vector<ll> a(n), b(n);
    priority_queue<Pll> que;
    bool is_same = true;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=0;i<n;++i){
        cin >> b[i];
    }
    for(int i=0;i<n;++i){
        if(b[i] != a[i]) {
            i_prev = (i == 0)?n-1:i-1;
            i_next = (i == n-1)?0:i+1;
            is_same = false;
            que.push(Pii(b[i], i));
        }
    }

    if(is_same) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0, bi_current, bi_prev;
    int i;
    while(!que.empty()) {
        tie(bi_current, i) = que.top();
        que.pop();

        i_prev = (i == 0)?n-1:i-1;
        i_next = (i == n-1)?0:i+1;

        int x = (bi_current - a[i]) / (b[i_prev] + b[i_next]);
        if(x <= 0) {
            ans = -1;
            break;
        }

        bi_prev = bi_current - x * (b[i_prev] + b[i_next]);
        b[i] = bi_prev;
        ans += x;

        if(b[i] != a[i]) {
            que.push(Pii(b[i], i));
        }
    }

    cout << ans << endl;

}
