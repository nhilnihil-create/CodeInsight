#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n) {
        rep(j,n-1) {
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());
    }

    typedef pair<int, int> P;
    vector<P> que;

    auto add = [&](int i) -> void {
        if (!a[i].size()) return;
        int j = a[i].back();
        if (a[j].back() == i) {
            que.emplace_back(i,j);
            if (que.back().first > que.back().second) {
                swap(que.back().first, que.back().second);
            }
        }
    };

    rep(i,n) {
        add(i);
    }

    int ans = 0;
    while (!que.empty()) {
        ans++;
        sort(que.begin(), que.end());
        que.erase(unique(que.begin(), que.end()), que.end());
        vector<P> pre;
        swap(pre, que);
        rep(i,pre.size()) {
            int j = pre[i].first;
            int k = pre[i].second;
            a[j].pop_back();
            a[k].pop_back();
            add(j);
            add(k);
        }
    }

    rep(i,n) {
        if (a[i].size()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}