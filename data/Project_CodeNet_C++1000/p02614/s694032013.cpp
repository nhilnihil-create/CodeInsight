#include<bits/stdc++.h>

#define ntest 0

using namespace std;

int h,w,k,res;
int cal(int x, int y, vector<vector<char>> v) {
    for (int i = 0; i < h; ++i)
    if (x&(1<<i)) {
        for (int j = 0; j < w; ++j) v[i][j] = '$';
    }
    for (int i = 0; i < w; ++i)
    if (y & (1<<i)) {
        for (int j = 0; j < h; ++j) v[j][i] = '$';
    }
    int cnt = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) cnt += v[i][j] == '#';
    return cnt == k;
}
void solve() {
    cin >> h >> w >> k;
    vector<vector<char>> c(h,vector<char>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) cin >> c[i][j];
    for (int i = 0; i < (1<<h); ++i)
        for (int j = 0; j < (1<<w); ++j) res += cal(i,j, c);
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


