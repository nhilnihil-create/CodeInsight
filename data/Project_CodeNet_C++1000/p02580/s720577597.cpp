#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    set<pair<int, int>> targets;
    vector<int> hSum(H), wSum(W);
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        targets.insert({x - 1, y - 1});
        hSum[x - 1]++;
        wSum[y - 1]++;
    }

    int maxWVal = 0, maxHVal = 0;
    vector<int> maxWs, maxHs;

    for(int i = 0; i < H; i++) {
        if(hSum[i] > maxHVal) {
            maxHs.clear();
            maxHs.push_back(i);
            maxHVal = hSum[i];
        } else if(hSum[i] == maxHVal) {
            maxHs.push_back(i);
        }
    }
    for(int j = 0; j < W; j++) {
        if(wSum[j] > maxWVal) {
            maxWs.clear();
            maxWs.push_back(j);
            maxWVal = wSum[j];
        } else if(wSum[j] == maxWVal) {
            maxWs.push_back(j);
        }
    }

    int ans = maxWVal + maxHVal - 1;
    bool ok = false;
    for(int w : maxWs) {
        for(int h : maxHs) {
            if(targets.find({h, w}) == targets.end()) {
                ans += 1;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << ans << endl;
}