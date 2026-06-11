#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> hCount(h), wCount(w);
    int hMax = 0, wMax = 0;
    set<pair<int, int>> bombs;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        hMax = max(hMax, ++hCount[x]), wMax = max(wMax, ++wCount[y]);
        bombs.insert({x, y});
    }

    vector<int> hCand, wCand;
    for (int i = 0; i < h; i++) {
        if (hCount[i] == hMax)hCand.push_back(i);
    }
    for (int i = 0; i < w; i++) {
        if (wCount[i] == wMax)wCand.push_back(i);
    }

    for (auto &x:hCand) {
        for (auto &y:wCand) {
            if (bombs.count({x, y}) == 0) {
                cout << hMax + wMax << endl;
                return 0;
            }
        }
    }

    cout << hMax + wMax - 1 << endl;
    return 0;
}