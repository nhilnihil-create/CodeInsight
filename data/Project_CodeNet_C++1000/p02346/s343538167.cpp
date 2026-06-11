#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define rep(i,x) for(int i=0;i<(x);++i)
#define rep1(i,x) for(int i=1;i<=(x);++i)
#define rrep(i,x) for(int i=(x)-1;i>=0;--i)
#define rrep1(i,x) for(int i=(x);i>=1;--i)
#define FOR(i,a,x) for(int i=(a);i<(x);++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false);cin.tie(0)

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T get(){T a;cin>>a;return a;}
template<typename T>T rev(T a){reverse(all(a));return a;}
template<typename T>istream&operator>>(istream&is,vector<T>&vec){rep(i,vec.size())is>>vec[i];return is;}
template<typename T>vector<T>&sort(vector<T>&a){sort(all(a));return a;}

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

struct segtree {
    int n;
    vi seg;

    void init(int n_)
    {
        n = 1;
        while (n < n_) n *= 2;
        seg.resize(2 * n - 1);
        rep(i, 2 * n - 1) seg[i] = 0;
    }

    int update(int k, int a)
    {
        k += n - 1;

        seg[k] += a;

        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] += a;
        }
    }

    int query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l) return 0;

        if (a <= l && r <= b) return seg[k];

        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

        return vl + vr;
    }

    int query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }
};

signed main()
{
    int N, Q; cin >> N >> Q;

    segtree s;

    s.init(N);

    rep(i, Q) {
        int c, x, y; cin >> c >> x >> y;

        if (c == 0) {
            -- x;
            s.update(x, y);
        } else {
            -- x; -- y;
            cout << s.query(x, y + 1) << endl;
        }
    }
}