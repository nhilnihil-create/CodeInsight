#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<vector<int>> dir2 = {{0, 1}, {1, 0}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
const int INF = 1e9;


int main()
{
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)cin >> s[i];
    vector<vector<int>> dp(h, vector<int>(w, INF)); //dp[i][j] := [i][j]に行く時に通る最小の黒集団
    dp[0][0] = s[0][0] == '#';

    queue<pair<int,int>> que;
    que.push({0, 0});
    dp[0][0] = s[0][0] == '#';

    while(que.size()) {
        auto cur = que.front();                 
        que.pop();
        for(auto d : dir2) {
            int ny = d[0] + cur.first;
            int nx = d[1] + cur.second;
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)continue;
            if(dp[ny][nx] > dp[cur.first][cur.second] + (s[ny][nx] == '#' && s[cur.first][cur.second] == '.')) {
                dp[ny][nx] = dp[cur.first][cur.second] + (s[ny][nx] == '#' && s[cur.first][cur.second] == '.' );
                que.emplace(ny, nx);
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}