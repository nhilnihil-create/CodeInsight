#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> elevations;
    vector<bool> hill(n,true);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        elevations.push_back(h);
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (elevations[a-1] <= elevations[b-1]) {
            hill[a-1] = false;
        }
        if (elevations[b-1] <= elevations[a-1]) {
            hill[b-1] = false;
        }
    }
    int peaks = 0;
    for (int i = 0; i < n; i++) {
        if (hill[i] == true) {
            peaks += 1;
        }
    }
    cout << peaks;
}
