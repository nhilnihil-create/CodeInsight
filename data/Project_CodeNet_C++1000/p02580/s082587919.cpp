#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

int main(void)
{   
    int H, W, M;
    cin >> H >> W >> M;

    int h, w;
    vector<int> hc(H,0), wc(W,0);
    set<pair<int,int>> s;
    int hmax=0;
    int wmax=0;
    for(int i = 0; i < M; ++i){
        cin >> h >> w;
        h--;
        w--;
        hc[h]++;
        wc[w]++;
        s.emplace(P(h,w));
    }

    vector<int> seth, setw;
    for(int i=0; i < H; i++){
        if(hmax < hc[i]){
            hmax = hc[i];
        }
    }
    for(int i=0; i < W; i++){
        if(wmax < wc[i]){
            wmax = wc[i];
        }
    }

    for(int i=0; i < H; i++){
        if(hc[i] == hmax){
            seth.push_back(i);
        }
    }
    for(int i=0; i < W; i++){
        if(wc[i] == wmax){
            setw.push_back(i);
        }
    }

    int ans = wmax + hmax;
    for(int i : seth) for(int j : setw) {
        if(s.count(P(i, j)) != 0 ) continue;
        cout << ans << endl;
        return 0;
    }

    ans--;

    cout << ans << endl;

}
