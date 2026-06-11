#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<string> data(h); rep(i,h) cin >> data[i];
    vector<vector<int>> ans(h,vector<int>(w,0));

    if(data[0][0] == '#') ans[0][0] = 1;
    rep(i,w-1){
        if(data[0][i+1] == '#' && data[0][i] == '.') ans[0][i+1] = ans[0][i] + 1;
        else ans[0][i+1] = ans[0][i];
    }
    rep(i,h-1){
        if(data[i+1][0] == '#' && data[i][0] == '.') ans[i+1][0] = ans[i][0] + 1;
        else ans[i+1][0] = ans[i][0];
    }
    rep(i,h-1) rep(j,w-1){
        if(data[i+1][j+1] == '#' && data[i][j+1] == '.' && data[i+1][j] == '.')
            ans[i+1][j+1] = min(ans[i][j+1], ans[i+1][j]) + 1;
        else if(data[i+1][j+1] == '#' && data[i][j+1] == '#' && data[i+1][j] == '.')
            ans[i+1][j+1] = min(ans[i][j+1], ans[i+1][j]+1);
        else if(data[i+1][j+1] == '#' && data[i][j+1] == '.' && data[i+1][j] == '#')
            ans[i+1][j+1] = min(ans[i][j+1]+1, ans[i+1][j]);
        else ans[i+1][j+1] = min(ans[i][j+1], ans[i+1][j]);
    }
    cout << ans[h-1][w-1] << endl;
}