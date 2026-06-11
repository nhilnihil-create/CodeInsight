#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n) {
        rep(j,n-1) {
            cin >> a[i][j];
            --a[i][j];
        }
        reverse(all(a[i]));
    }
    vector<P> q;
    auto check = [&](int i) {
        if (a[i].size()==0) return;
        int j = a[i].back();
        if (a[j].size()==0) return;
        if (a[j].back()==i) {
            P p(i,j);
            if (p.se > p.fi) swap(p.se, p.fi);
            q.pb(p);
        }
    };

    rep(i,n) check(i);

    int day = 0;
    while (q.size() > 0) {
        ++day;
        sort(all(q));
        q.erase(unique(all(q)), q.end());
        vector<P> prevq;
        swap(q,prevq);

        for (auto p: prevq) {
            int i = p.fi, j = p.se;
            a[i].pop_back();
            a[j].pop_back();
        }
        for (auto p: prevq) {
            int i = p.fi, j = p.se;
            check(i);
            check(j);
        }
    }
    rep(i,n) {
        if (a[i].size()!=0) {
            puts("-1");
            return 0;
        }
    }
    cout << day << endl;
    return 0;
}




