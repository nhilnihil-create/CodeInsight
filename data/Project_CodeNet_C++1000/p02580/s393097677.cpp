#include <iostream>
#include <vector>
#include <set>
using namespace std;

void set_reset(set<int> &s) {
    set<int> s2;
    s = s2;
}

int main(void){
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> h(M), w(M);
    vector<int> hzt(H), vtc(W);
    for (int i = 0; i < M; i++) {
        cin >> h[i] >> w[i];
        h[i]--; w[i]--;
    }
    for (int i = 0; i < M; i++) {
        vtc[w[i]]++;
        hzt[h[i]]++;
    }
    int vtc_max = 0;
    set<int> vtc_n;
    for (int i = 0; i < W; i++) {
        if (vtc_max < vtc[i]) {
            vtc_max = vtc[i];
            set_reset(vtc_n);
            vtc_n.insert(i);
        }
        else if (vtc_max == vtc[i]) {
            vtc_n.insert(i);
        }
    }
    int hzt_max = 0;
    set<int> hzt_n;
    for (int i = 0; i < H; i++) {
        if (hzt_max < hzt[i]) {
            hzt_max = hzt[i];
            set_reset(hzt_n);
            hzt_n.insert(i);
        }
        else if (hzt_max == hzt[i]) {
            hzt_n.insert(i);
        }
    }
    int cross_bomb_count = 0;
    for (int i = 0; i < M; i++) {
        if (hzt_n.count(h[i]) && vtc_n.count(w[i])) {
            cross_bomb_count++;
        }
    }
    if (cross_bomb_count == vtc_n.size() * hzt_n.size()) cout << vtc_max + hzt_max - 1 << endl;
    else cout << vtc_max + hzt_max << endl;
}