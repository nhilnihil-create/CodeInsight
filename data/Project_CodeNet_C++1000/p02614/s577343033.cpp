#include <iostream>
#include <vector>
using namespace std;

vector<string> c;

int cntB(int bh, int bw) {
    int cnt = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (bh & (1 << i)) continue;
        for (int j = 0; j < c[i].size(); ++j) {
            if (bw & (1 << j)) continue;
            if (c[i][j] == '#') cnt++;
        }
    }
    return cnt;
}

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    c.resize(h);
    for (int i = 0; i < h; ++i) {
        cin >> c[i];
    }
    int ans = 0;
    for (int b1 = 0; b1 < (1 << h); ++b1) {
        for (int b2 = 0; b2 < (1 << w); ++b2) {
            if (cntB(b1, b2) == k) ans++;
        }
    }
    cout << ans << endl;
}