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
    rep(i,n) rep(j,n-1) {
        cin >> a[i][j];
        a[i][j]--;
    }
    rep(i,n) reverse(a[i].begin(), a[i].end());

    typedef pair<int, int> P;
    vector<P> que;
    auto set = [&](int i) -> void {
        if (a[i].size()==0) return;
        int j = a[i].back();
        if (a[j].back() == i) {
            if (i > j) swap(i,j);
            que.emplace_back(i,j);
        }
    };

    rep(i,n) set(i);

    int ans = 0;
    while (!que.empty()) {
        ans++;
        sort(que.begin(), que.end());
        que.erase(unique(que.begin(), que.end()), que.end());
        vector<P> tmp;
        swap(tmp, que);
        for (auto v : tmp) {
            a[v.first].pop_back();
            a[v.second].pop_back();
        }
        for (auto v : tmp) {
            set(v.first);
            set(v.second);
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