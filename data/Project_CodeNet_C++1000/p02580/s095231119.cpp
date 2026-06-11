/*input
2 3 3
2 2
1 1
1 3
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// antbook p155
const int INF = 1001001001;
struct SegmentTree {
    int n; // size/2
    vector<int> dat; // a segment tree
    // n: num of elements
    SegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        // set all elements at INF
        dat.resize(2*n-1, INF);
    }
    // update k-th element by a
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // returns min[a, b)
    // k-th node is [l, r)
    // use like query(a, b)
    int query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if  (r < 0) r = n;
        // INF if intersection of [a, b) and [l, r) is empty
        if (r <= a || b <= l) return INF;
        // val of this node if [a, b) includes [l, r)
        if (a <= l && r <= b) return dat[k];
        // min of 2 children
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    } 
};

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> ch(h), cw(w);
    vector<int> bom[h];
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ch[x]++; cw[y]++;
        bom[x].push_back(y);
    }

    int ans = 0;
    SegmentTree st(w);
    rep(i, w) st.update(i, -cw[i]);
    rep(i, h) {
        for (auto y: bom[i]) st.update(y, -cw[y]+1);
        ans = max(ans, ch[i]-st.query(0, w));
        for (auto y: bom[i]) st.update(y, -cw[y]);
    }
    cout << ans << endl;
}