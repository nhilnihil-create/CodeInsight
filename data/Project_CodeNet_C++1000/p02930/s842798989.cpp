#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

int n;
vector<vector<int>> level;

void dfs(int start, int end, int depth) {
    if(start >= end) return;
    int mid = (start+end)/2;
    for(int i = start; i <= mid; ++i) {
        for(int j = mid+1; j <= end; ++j) {
            level[i][j] = depth;
        }
    }
    
    dfs(start, mid, depth+1);
    dfs(mid+1, end, depth+1);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    level.resize(n+1, vector<int>(n+1));

    dfs(1, n, 1);

    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            cout << level[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
