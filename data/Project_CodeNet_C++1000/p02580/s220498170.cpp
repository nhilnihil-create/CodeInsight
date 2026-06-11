#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

struct SegTree {
    vector<int> vseg;
    int n;
    #define CL(v) ((v) << 1)
    #define CR(v) ((v) << 1 | 1)

    SegTree(vector<int> a){
        this->n = a.size();
        vseg.resize(n << 2);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int v, int tl, int tr){
        if(tl == tr)
            vseg[v] = a[tl];
        else{
            int tm = tl + tr >> 1;
            build(a, CL(v), tl, tm);
            build(a, CR(v), tm + 1, tr);
            vseg[v] = max(vseg[CL(v)], vseg[CR(v)]);
        }
    }

    int getMax() {
        return vseg[1];
    }

    void update(int pos, int diff){
        update(1, 0, n - 1, pos, diff);
    }

    void update(int v, int tl, int tr, int pos, int diff) {
        if(tl == tr){
            vseg[v] += diff;
        }else{
            int tm = tl + tr >> 1;
            if (pos <= tm)
                update(CL(v), tl, tm, pos, diff);
            else
                update(CR(v), tm + 1, tr, pos, diff);
            vseg[v] = max(vseg[CL(v)], vseg[CR(v)]);
        }
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, x, t, h, w, m;
    cin >> h >> w >> m;
    vector<ii> v(m);
    vector<vector<int>> line(h);
    vector<int> col(w, 0);
    for(int i = 0; i < m; i++){
        cin >> v[i].first >> v[i].second;
        v[i].first --; v[i].second--;
        line[v[i].first].push_back(v[i].second);
        col[v[i].second]++;
    }
    SegTree seg(col);
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int e: line[i])
            seg.update(e, - 1);
        ans = max<int>(ans, line[i].size() + seg.getMax());
        for(int e: line[i])
            seg.update(e, 1);
    }
    cout << ans << endl;
}