#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int H,W;

int dx[2] = {1,0};
int dy[2] = {0,1};

void bfs(vector<vector<char>> &c, vector<vector<int>> &seen) {
    int cnt = 0;
    queue<P> qw,qb;
    vector<vector<bool>> queued(H,vector<bool>(W,false));
    
    bool now = true;
    if (c[0][0]=='.') {
        qw.push(make_pair(0,0));
        queued[0][0] = true;
    }
    else {
        qb.push(make_pair(0,0));
        queued[0][0] = true;
    }
    while(qb.size() || qw.size()) {
        if (now) {
            while(qw.size()) {
                auto q = qw.front();
                qw.pop();
                int h,w;
                h = q.first;
                w = q.second;
                seen[h][w] = cnt;
                
                rep(i,2) {
                    if (h+dy[i]>=H || w+dx[i]>=W) {
                        continue;
                    }
                    else if (seen[h+dy[i]][w+dx[i]]!=INF) continue;
                    else if (queued[h+dy[i]][w+dx[i]] == true) continue;
                    else if (c[h+dy[i]][w+dx[i]]=='#') {
                        qb.push(make_pair(h+dy[i],w+dx[i]));
                        queued[h+dy[i]][w+dx[i]] = true;
                    }
                    else {
                        qw.push(make_pair(h+dy[i],w+dx[i]));
                        queued[h+dy[i]][w+dx[i]] = true;
                    }
                }
            }
            cnt++;
            now = false;
        }
        if (!now) {
            while(qb.size()) {
                auto q = qb.front();
                qb.pop();
                int h,w;
                h = q.first;
                w = q.second;
                seen[h][w] = cnt;
                
                rep(i,2) {
                    if (h+dy[i]>=H || w+dx[i]>=W) {
                        continue;
                    }
                    else if (seen[h+dy[i]][w+dx[i]]!=INF) continue;
                    else if (queued[h+dy[i]][w+dx[i]] == true) continue;
                    else if (c[h+dy[i]][w+dx[i]]=='.') {
                        qw.push(make_pair(h+dy[i],w+dx[i]));
                        queued[h+dy[i]][w+dx[i]] = true;
                    }
                    else {
                        qb.push(make_pair(h+dy[i],w+dx[i]));
                        queued[h+dy[i]][w+dx[i]] = true;
                    }
                }
            }
            cnt++;
            now = true;
        }
    }
}

int main(){
    cin >> H >> W;

    vector<vector<char>> c(H,vector<char>(W));
    vector<vector<int>> seen(H,vector<int>(W,INF));

    rep(h,H) {
        string tmp;
        cin >> tmp;
        rep(w,W) {
            c[h][w] = tmp[w];
        }
    }
    bfs(c,seen);
    if (c[H-1][W-1]=='.') {
        cout << seen[H-1][W-1]/2 << endl;
    }
    else {
        cout << seen[H-1][W-1]/2+1 << endl;
    }

}
