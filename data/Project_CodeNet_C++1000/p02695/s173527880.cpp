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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs(int n, int m, int pre_num, vector<int> now, vector<vector<int>> &num) {
    if ((int)now.size() == n) {
        num.push_back(now);
        return;
    }
    for (int i = pre_num; i <= m; ++i) {
        auto tmp_now = now;
        tmp_now.push_back(i);
        dfs(n, m, i, tmp_now, num);
    }
    return;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q);
    vector<int> b(q);
    vector<int> c(q);
    vector<int> d(q);
    rep(i, q) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b >> c[i] >> d[i];
        --tmp_a, --tmp_b;
        a[i] = tmp_a;
        b[i] = tmp_b;
    }
    vector<vector<int>> num;
    vector<int> now;
    dfs(n, m, 1, now, num);
    int ans = 0;
    //for (auto p: num) {
    //    for (auto v: p) {
    //        cout << v << " ";
    //    }
    //    cout << endl;
    //}
    rep(i, (int)num.size()) {
        int sum = 0;
        rep(j, q) {
            if (num[i][b[j]] - num[i][a[j]] == c[j]) sum += d[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
