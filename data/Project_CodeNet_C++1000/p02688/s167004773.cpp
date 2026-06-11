#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> di;
vector<vector<int>> Ai;

void input() {
    cin >> n >> k;
    di.resize(k);
    Ai.resize(k, vector<int>());

    for(int i = 0; i < k; i++) {
        cin >> di.at(i);
        Ai[i].resize(di.at(i));
        for(int j = 0; j < di.at(i); j++) {
            cin >> Ai[i][j];
            //cout << Ai[i][j];
        }
        //cout << endl;
    }
}

void solve() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        bool have = false;
        for(auto v : Ai) {
            for(auto p : v) {
                if(p == i) have = true;
            }
        }
        //if(!have)としても判定可能
        if (have == false) ans++;
    }
    cout << ans << endl;
}

int main() {
    input();
    solve();

    return 0;
}