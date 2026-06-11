#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int H, W, M;
    cin >> H >> W >> M;
    int h[M], w[M];
    int ch[H]{}, cw[W]{};
    int hmax = 0;
    int wmax = 0;
    for (int i = 0; i < M; i++) {
        cin >> h[i] >> w[i];
        h[i]--;
        w[i]--;
        ch[h[i]]++;
        cw[w[i]]++;
        hmax = max(hmax, ch[h[i]]);
        wmax = max(wmax, cw[w[i]]);
    }
    int hh = 0;
    int ww = 0;
    for (int i = 0; i < H; i++) {
        if (hmax == ch[i]) hh++;
    }
    for (int i = 0; i < W; i++) {
        if (wmax == cw[i]) ww++;
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (ch[h[i]] == hmax && cw[w[i]] == wmax) cnt++;
    }
    if (cnt==hh*ww) {
        cout << hmax + wmax - 1<< endl;
    } else {
        cout << hmax + wmax << endl;
    }
    return 0;
}