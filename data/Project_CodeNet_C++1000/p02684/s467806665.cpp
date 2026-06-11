#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> g(n);
    rep(i, n) {
        int a;
        cin >> a;
        --a;
        g[i] = a;
    }
    vector<int> cnt(n, -1);
    int now = 0;
    cnt[0] = 0;
    while(1) {
        if (cnt[now] == k) {
            cout << now + 1 << endl;
            return 0;
        }
        if (cnt[g[now]] != -1) {
            ll loop_num = cnt[now] - cnt[g[now]] + 1;
            ll rest = k - cnt[now] - 1;
            ll fin = g[now];
            //cout << rest << " " << loop_num << " " << fin << " " << rest % loop_num << endl;
            rep(i, rest % loop_num + 1) {
                now = g[now];
            }
            cout << now + 1 << endl;
            break;
        }
        cnt[g[now]] = cnt[now] + 1;
        now = g[now];
    }
    return 0;
}
