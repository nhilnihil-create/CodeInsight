#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, m;    cin >> h >> w >> m;
    vector<int> hc(h, 0), wc(w, 0);
    vector<vector<int> > p(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> p[i][0] >> p[i][1];
        p[i][0]--;  p[i][1]--;
        hc[p[i][0]]++;
        wc[p[i][1]]++;
    }

    int mh = 0, mw = 0;
    for (int i = 0; i < h; i++) 
        mh = max(mh, hc[i]);
    long long th = 0;
    for (int i = 0; i < h; i++) {
        if (mh == hc[i])
            th++;
    }
    for (int i = 0; i < w; i++)
        mw = max(mw, wc[i]);
    long long tw = 0, cnt = 0;
    for (int i = 0; i < w; i++) {
        if (mw == wc[i])
            tw++;
    }

    for (int i = 0; i < m; i++) {
        if (hc[p[i][0]] == mh && wc[p[i][1]] == mw)
            cnt++;
    }

    

    if (cnt >= th*tw)
        cout << mh + mw -1 << endl;
    else 
        cout << mh + mw << endl;
    return 0;
}