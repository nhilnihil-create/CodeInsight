#include<cstdio>
#include<map>
#include<set>
using namespace std;

const int MAX = 3e5;
int h, w, m;
int hi[MAX], wi[MAX];
map<int, int> mh, mw;
int xh, xw;
set<int> nh, nw;

int main() {
    scanf("%d %d %d", &h, &w, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &hi[i], &wi[i]);
        mh[--hi[i]]++;
        mw[--wi[i]]++;
        if (xh < mh[hi[i]]) xh = mh[hi[i]];
        if (xw < mw[wi[i]]) xw = mw[wi[i]];
    }
    for (auto &x : mh) {
        if (x.second == xh) nh.insert(x.first);
    }
    for (auto &x : mw) {
        if (x.second == xw) nw.insert(x.first);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (nh.find(hi[i]) != nh.end() && nw.find(wi[i]) != nw.end()) cnt++;
    }
    printf("%d\n", cnt < nh.size() * nw.size() ? xh + xw : xh + xw - 1);
    return 0;
}
