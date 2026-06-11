#include <bits/stdc++.h>
using namespace std;
int w[1000000+10],h[1000000+10];
set<int> adj[1000000+10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H,W,M;
    cin >> H >> W >> M;
    int maxH=-1,maxW=-1;
    for (int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        adj[a].insert(b);
        w[b]++;
        h[a]++;
    }
    for (int i = 0; i <= W; i++) {
        maxW = max(maxW, w[i]);
    }
    for (int i = 0; i <= H; i++) {
        maxH = max(maxH, h[i]);
    }
    vector<int> hs,ws;
    for (int i = 0; i <= W; i++) {
        if (w[i]==maxW) ws.push_back(i);
    }
    for (int i = 0; i <= H; i++) {
        if (h[i]==maxH) hs.push_back(i);
    }
    if (hs.size()*ws.size()>M) {
        cout << maxH+maxW << endl;
    }
    else {
        for (int i = 0; i < (int)hs.size(); i++) {
            for (int j = 0; j < (int)ws.size(); j++) {
                int x=hs[i],y=ws[j];
                if (adj[x].find(y) == adj[x].end()) {
                    cout << maxH+maxW << endl;
                    goto done;
                }
            }
        }
        cout << maxH+maxW-1 << endl;
    }

    done: return 0;
}