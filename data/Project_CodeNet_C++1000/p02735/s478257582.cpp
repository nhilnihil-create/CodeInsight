#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int h,w;
    cin >> h >> w;
    string sur[h];
    bool first = 0,second = 0;

    for(int i = 0; i < h; i++) cin >> sur[i];

    pair<int,int> s = make_pair(0,0);
    pair<int,int> g = make_pair(h-1,w-1);
    map<pair<int,int>,int> depth;
    map<pair<int,int>,bool> seen;
    queue<pair<int,int>> que;
    const int n_select = 2;
    int dx[n_select] = {0,1};
    int dy[n_select] = {1,0};
    if(sur[s.first][s.second] == '#') first = 1;
    if(sur[g.first][g.second] == '#') second = 1;

    que.push(s);
    depth[s] = 0;
    seen[s] = true;

    while(!que.empty()){
        pair<int,int> now = que.front();
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        for(int i = 0; i < n_select; i++){
            if(0 <= y+dy[i] && y+dy[i] < h && 0 <= x+dx[i] && x+dx[i] < w){
                int nxy = y+dy[i];
                int nxx = x+dx[i];
                pair<int,int> nxt = make_pair(nxy,nxx);
                int d = 0;
                if(sur[nxy][nxx] != sur[y][x]) d = 1;
                if(!seen[nxt] || depth[nxt] > depth[now]+1){
                    seen[nxt] = true;
                    depth[nxt] = depth[now]+d;
                    que.push(nxt);
                }  
            }
        }
    }

    /*for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            pair<int,int> tmp = make_pair(i,j);
            cout << depth[tmp];
        }
        cout << endl;
    }*/

    cout << depth[g]/2+min(first+second,1) << endl;

    return 0;
}