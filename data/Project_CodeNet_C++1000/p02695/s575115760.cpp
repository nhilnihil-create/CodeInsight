#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define M 1000000007
//#define FILE_A_IN
using vvi=vector<vector<int>>;

int n, m, q;
void dfs(vector<vector<int>>& va, vector<int> vt, int next, int& ans) {
    if(vt.size() == n) {
        int s = 0;
        for (auto e : va) {
            if(vt[e[1]-1] - vt[e[0]-1] == e[2]) {
                s += e[3];
            }
        }
        ans = max(s, ans);
        return;
    }
    for (int i = next; i < m+1; ++i) {
        vt.push_back(i);
        dfs(va, vt, i, ans);
        vt.pop_back();
    }
}
void solve() {
    int ans = 0;
    cin >> n >> m >> q;
    vvi va;
    for (int i = 0; i < q; ++i) {
        vector<int> vt(4);
        for (int j = 0; j < 4; j++) {
            cin >> vt[j];
        }
        va.push_back(vt);
    }
    vector<int> vt;
    dfs(va, vt, 1, ans);
    cout << ans << endl;
}
int main() {
#ifdef FILE_A_IN
    freopen("a.in", "r", stdin);
#endif
    fio;
        solve();
    return 0;
}